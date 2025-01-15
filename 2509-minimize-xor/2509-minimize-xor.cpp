class Solution {
public:
string integerToBinary(int number) {
    string binary = "";
    if (number == 0) return "0";
    while (number > 0) {
        binary = to_string(number % 2) + binary; 
        number /= 2; 
    }
    return binary;
}
    int minimizeXor(int n1, int n2) {
      string p=  integerToBinary(n1);
      int cnt1= count(p.begin(), p.end(), '1');
        string n=  integerToBinary(n2);
         int cnt2= count(n.begin(), n.end(), '1');
         if(cnt1==cnt2)return n1;
         if(cnt1>cnt2)
         {
            int i=p.length()-1;
            while(i>=0&&cnt1>cnt2)
            {
               if(p[i]=='1')
               {
                 p[i]='0';
                 cnt1--;
               }
               i--;
            }
           return stoi(p, nullptr, 2); 
         }

         if(cnt1<cnt2)
         { 
            int t= cnt2-cnt1;
             int i=p.length()-1;
            while(i>=0)
            {
                if(p[i]=='0'&&t>0)
                {
                  p[i]='1';
                    t--;
                }
                i--;
               
              
            }
            while (t > 0) {
                p= '1' + p;
                t--;
            }

            return stoi(p, nullptr, 2); 

         }



   return 0;
        
    }
};