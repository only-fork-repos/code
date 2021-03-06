#ifndef ASPECTPARSER_H
#define ASPECTPARSER_H

#include <string>
#include <list>
//#include <stack>
#include <deque>
#include <sstream>

class AspectParserException : public std::exception {
public:
    AspectParserException(const std::string& msg_) : msg(msg_) {}
    virtual ~AspectParserException() throw() {}
    virtual const char* what() const throw() { return msg.c_str(); }
private:
    std::string msg;
};


class AspectParser {
public:
    AspectParser();
    void addAspect(const std::string& aspect);
    void parseFile(const char* filename);
private:
    void parse(char* data, unsigned int size, std::stringstream& output);
    void readLine(char* input, bool hasNewLine, std::stringstream& output);
    bool updateState();
    void beginAspect(const std::string& name);
    void endAspect(const std::string& name);
    void error(const std::string& msg);
    bool knownAspect(const std::string& name) const;

    typedef std::deque<std::string> Stack;
    typedef Stack::const_iterator StackConstIter;
    Stack aspectStack;

    typedef std::list<std::string> Aspects;
    typedef Aspects::const_iterator AspectsConstIter;
    Aspects aspects;

    unsigned int line;
    bool copyInput;
};

#endif

