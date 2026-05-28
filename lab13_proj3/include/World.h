#pragma once
#include<vector>
#include<memory>
#include "Entity.h"


class World{
public:
    void addEntity(std::unique_ptr<Entity>ptr){
        entities.emplace_back(std::move(ptr));
    }
    void clear(){
        entities.clear();
    }

    class Iterator{
    public:
        Iterator(World* d, size_t id):data(d),idx(id){}
        bool operator==(const Iterator& other)const{
            return idx == other.idx;
        }
        bool operator!=(const Iterator& other)const{
            return idx != other.idx;
        }

        Entity& operator*(){
            return *(data->entities[idx]);
        }

        const Entity& operator*()const{
            return *(data->entities[idx]);
        }

        Entity* operator->(){
            return (data->entities[idx].get());
        }

        Iterator& operator++(){
            ++idx;
            return *this;
        }
        
    private:
        World* data;
        size_t idx;
    };

    Iterator begin(){
        return Iterator(this,0);
    }
    Iterator end(){
        return Iterator(this,entities.size());
    }
private:
    std::vector<std::unique_ptr<Entity>> entities;
};

