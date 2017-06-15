#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <cctype>
#include <cstring>
std::stack<int> stck;
int analys(std::string s1)
{
    int res;
    if(s1=="+"){
        int tmp_x,tmp_y,tmp;
        tmp_y=stck.top();
        stck.pop();
        tmp_x=stck.top();
        stck.pop();
        tmp=tmp_x+tmp_y;
        stck.push(tmp);
        // std::cout<<tmp_x<<"+"<<tmp_y<<"="<<tmp<<std::endl;
    }
    else if(s1=="-"){
        int tmp_x,tmp_y,tmp;
        tmp_y=stck.top();
        stck.pop();
        tmp_x=stck.top();
        stck.pop();
        tmp=tmp_x-tmp_y;
        stck.push(tmp);
        //std::cout<<tmp_x<<"-"<<tmp_y<<"="<<tmp<<std::endl;
    }
    else if(s1=="*"){
        int tmp_x,tmp_y,tmp;
        tmp_y=stck.top();
        stck.pop();
        tmp_x=stck.top();
        stck.pop();
        tmp=tmp_x*tmp_y;
        stck.push(tmp);
        //std::cout<<tmp_x<<"*"<<tmp_y<<"="<<tmp<<std::endl;
    }
    else if(s1=="/"){
        double tmp_x,tmp_y,tmp;
        tmp_y=stck.top();
        stck.pop();
        tmp_x=stck.top();
        stck.pop();
        tmp=tmp_x/tmp_y;
        stck.push(tmp);
        //std::cout<<tmp_x<<"/"<<tmp_y<<"="<<tmp<<std::endl;
    }
    else{
        res=atoi(s1.c_str());
        //std::cout<<"pushing"<<res<<std::endl;
        stck.push(res);
    }
    return stck.top();
}
int count(std::string exprass){
    int j=0;
    std::string tmp_o="";
    for(unsigned int i=0;i<exprass.size()+1;i++){
        while(exprass[j]!=' '){
            tmp_o.push_back(exprass[j]);
            j++;
        }
        analys(tmp_o);
        //std::cout<<"tmp= "<<tmp_o<<std::endl;
        std::size_t pos = exprass.find(" ");
        exprass = exprass.substr (pos+1);
        tmp_o.clear();
        exprass+=" ";
        //  std::cout<<exprass<<std::endl;
        j=0;
    }
    return stck.top();
}

void start(std::string s){
    std::cout<<"\E[H\E[J";//    system("clear");
    std::cout<<"Exprassion:"<<std::endl;
    std::cout<<s<<" = "<<count(s)<<std::endl;
}
int Diskriminant(){
    int a,b,c;
    std::cout<<"Vvedite a,b,c"<<std::endl;
    std::cin>>a;
    std::cin>>b;
    std::cin>>c;
    std::string expr;
    std::string as=std::to_string(a);
    std::string bs=std::to_string(b);
    std::string cs=std::to_string(c);
    expr=expr+bs;
    expr=expr+" ";
    expr=expr+bs;
    expr=expr+" ";
    expr=expr+"*";
    expr=expr+" ";
    expr=expr+"4";
    expr=expr+" ";
    expr=expr+as;
    expr=expr+" ";
    expr=expr+cs;
    expr=expr+" ";
    expr=expr+"*";
    expr=expr+" ";
    expr=expr+"*";
    expr=expr+" ";
    expr=expr+"-";
    std::cout<<"Diskriminant "<<expr<<" = "<<count(expr)<<std::endl;
}
void menu(){
    int ch;
    std::string s;
    std::cout<<"1-Diskriminant 2-Exprassion"<<std::endl;
    std::cin>>ch;
    if(ch==2){
        std::cout<<"Exprassion:"<<std::endl;
        std::cin.ignore();
        std::getline(std::cin,s);
        start(s);
    }
    else if(ch==1){
        Diskriminant();
    }

}

int main()
{
    menu();
    return 0;
}
