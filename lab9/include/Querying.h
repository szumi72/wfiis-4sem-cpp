#pragma once
#include<vector>
#include<memory>

namespace Querying{
    //klasa podstawoawa query
    class Query{
    public:
        Query() = default;            

        //wirtualby destruktor
        virtual ~Query()=default;

        //metoda clone pozwalająca kopiować klasy z uniquye ptr
        virtual std::unique_ptr<Query> clone()const = 0;
        virtual bool operator()(int k)const=0;
    };
    
    namespace Simple{
        
        //sprawdza czy wieksze
        class GreaterThan:public Query{
        public:
            // GreaterThan(int v):Query(v){}
            GreaterThan(int v):war(v){}
            std::unique_ptr<Query> clone()const override{
                return std::make_unique<GreaterThan>(*this);
            }
            bool operator()(int k)const override{
                return k>war;
            }
            
        private:
            int war;
        };


        //klasa reprezentująca warunek mniejszości
        class LessThan:public Query{
        public:
            // LessThan(int v):Query(v){}
            LessThan(int v):war(v){}
            std::unique_ptr<Query> clone()const override{
                return std::make_unique<LessThan>(*this);
            }
            bool operator()(int k)const override{
                return k<war;
                
            }
            
        private:
            int war;
        };

        class IsEven:public Query{
        public:
            IsEven() = default;            
            std::unique_ptr<Query> clone()const override{
                return std::make_unique<IsEven>(*this);
            }
            bool operator()(int k)const override{
                return k%2==0;
            }
            
        private:
        };


        //sprawdza czy jest równe do podanej licznby
        class EqualTo:public Query{
        public:
            // EqualTo(int k){}
            EqualTo(int k):war(k){}
            std::unique_ptr<Query> clone()const override{
                return std::make_unique<EqualTo>(*this);
            }
            bool operator()(int k)const override{
                return war==k;
            }
            
        private:
            int war;
        };


        //zaprzeczenuie zapytania
        class NotQuery:public Query{
        public:
            NotQuery() = default;
            NotQuery(Query* q){
                child_ = std::unique_ptr<Query>(q);
            }
            std::unique_ptr<Query> clone()const override{
                return std::make_unique<NotQuery>(child_->clone().release());
            }
            bool operator()(int k)const override{
                if(child_){
                    return (!(*child_)(k));

                }
                return false;
            }
            void addChild(std::unique_ptr<Query> ptr){
                child_ = std::move(ptr);
            }
        private:
            std::unique_ptr<Query> child_;
        };

    }//namespace Simple


    //koompozytor łączy wszusktie query i zwraca ich wynikd
    class CompositeQuery : public Query{
    public:
        CompositeQuery(){
            queries_.resize(10);
        }
        CompositeQuery(int len){
            queries_.resize(len);
        }
        //konstruktor kopiujący
        CompositeQuery(const CompositeQuery& other){
            for(auto const& q:other.queries_){
                if(q){

                    queries_.emplace_back(q->clone());
                }
            }
        }
        void addQuery(std::unique_ptr<Query> query){
            queries_.emplace_back(std::move(query));
        }


        //metoda clone
        std::unique_ptr<Query> clone()const override{
            auto temp = std::make_unique<CompositeQuery>(queries_.size());
            for(auto const& q:queries_){
                temp->addQuery(q->clone());
            }
            return temp;
        }

        //zwraca prawde jeżeli wszyskite
        bool operator()(int k)const override{
            if(queries_.empty()){
                return true;
            }

            for(const auto& q:queries_){
                if(q){
                    if((*q)(k)){
                        continue;
                    }else{

                        return false;
                    }
                }
                
            }
            return true;

        }

    private:
        std::vector<std::unique_ptr<Query>> queries_;
    };


    //funkcja filtrująca na podstawie query
    std::vector<int> filter(std::vector<int>& v, const Query& query){
        
        std::vector<int> result;
        for(int i=0;i<v.size();i++){      
            if(query(v[i])){

                result.push_back(v[i]);
            }
            
        }
        return result;
    }


}//namespace Querying