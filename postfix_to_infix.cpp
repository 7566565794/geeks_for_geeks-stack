#include<bits/stdc++.h>
using namespace std;
bool isoperand(char c){
    if(c=='^'|| c=='*' || c=='/' || c== '+' || c=='-'){
        return true;
    }
    return false;
}
string preToInfix(string s){
    stack <string> st;
    string rs;
    string c1;
    string c2;
    int l=s.size();
    for(int i=0;i<l;i++){// --------------------and u have to change this line------------------
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
            st.push(string(1,s[i]));
        }
        else if(isoperand(s[i])){
             c1=st.top();st.pop();
             c2=st.top();st.pop();
             string temp = "(" + c1 + s[i] + c2 + ")";// --------------------only u have to change at this line-------------
            //  cout<<c1<<" "<<s[i]<<" "<<c2<<" ";
             st.push(temp);
            //  cout<<st.top();    
        }
        
    }
    return st.top();
}
int main() { 
  string pos_exp = "ab*c+"; ; 
  cout << "Infix : " << preToInfix(pos_exp); 
  return 0; 
} 
