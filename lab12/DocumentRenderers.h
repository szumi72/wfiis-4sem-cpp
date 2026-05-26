#pragma once
#include <string>
#include <cctype>
#include <memory>

//interfejs zapewniający metode render
class IDocumentRenderer{
public:
    virtual ~IDocumentRenderer()=default;
    //metoda pozwalajaca wyrenderowac content
    virtual std::string render(const std::string& msg)const=0;
};

//bazowa klasa do rendera zapewnia normilseze
class BaseDocumentRenderer: public IDocumentRenderer{
public:
    //metoda normalizujaca content(to lower case)
    std::string normalize(const std::string& msg)const{        
        std::string result="";
        for(unsigned char c:msg){
            result+=std::tolower(c);
        }
        return result;
    }
    virtual std::string render(const std::string& msg)const=0;
    
};

//zwykly render normalizuje content
class PlainTextRenderer:public BaseDocumentRenderer{
public:
    std::string render(const std::string& msg)const override{
        return normalize(msg);
    }
};

//render dodajacy nagłówki html
class HtmlRenderer:public BaseDocumentRenderer{
public:
    std::string render(const std::string& msg)const override{
        std::string result = "<html>\n<body>\n" + normalize(msg)+ "\n</body>\n</html>\n";
        return result;
    }
};

//klasa bazowa dla decoratora posiada refernejce do rendera
class RendererDecorator:public IDocumentRenderer{
public:
    RendererDecorator(IDocumentRenderer& renderer):renderer_(renderer){}   
    std::string render(const std::string& msg)const {
        return renderer_.render(msg);
    }
protected:    
    IDocumentRenderer& renderer_;
};

//dodaje header przy renderowaniu contentu
class HeaderDecorator:public RendererDecorator{
public:
    HeaderDecorator(const std::string& header,IDocumentRenderer& renderer):RendererDecorator(renderer),header_(header){}
    std::string render(const std::string& msg)const{        
        return header_ + "\n" + renderer_.render(msg);
    }
private:
    std::string header_;
};

//dodaje logowanie przy renderowaniu contentu
class LoggingDecorator:public RendererDecorator{
public:
    LoggingDecorator(IDocumentRenderer& renderer):RendererDecorator(renderer){}    
    std::string render(const std::string& msg)const{      
        std::string log = "[LOG] Rendering document with content:\n" + msg + "\n" + "[LOG] Result is: \n" + renderer_.render(msg)+"\n\n";

        return  log +  renderer_.render(msg);
    }
};