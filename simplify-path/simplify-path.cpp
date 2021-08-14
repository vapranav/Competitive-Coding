class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        if(path[len-1] != '/') {
            path+='/';
            len+=1;
        }
        int i = 1;
        string tmp = "";
        string res = "";
        stack<string> s;
        while(i<len) {
            if(path[i] == '/') {
                if(tmp == "" || tmp == ".") {
                    
                }
                else if(tmp == "..") {
                    if(!s.empty()) s.pop();
                } else {
                    s.push(tmp);
                }
                
                tmp = "";
            }
            else {
                tmp+=path[i];
            }
            ++i;
        }
        
        while(!s.empty()) {
            res="/"+s.top()+res;
            s.pop();
        }
        
        if(res.length() == 0) 
            res+="/";
        
        return res;
    }
};