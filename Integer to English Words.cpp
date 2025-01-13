class Solution {
public:
    unordered_map<string,string> mp;
    vector<string> answer;

    void fillMap(){
        mp["0"]="Zero";
        mp["1"]="One";
        mp["2"]="Two";
        mp["3"]="Three";
        mp["4"]="Four";
        mp["5"]="Five";
        mp["6"]="Six";
        mp["7"]="Seven";
        mp["8"]="Eight";
        mp["9"]="Nine";
        mp["10"]="Ten";
        mp["11"]="Eleven";
        mp["12"]="Twelve";
        mp["13"]="Thirteen";
        mp["14"]="Fourteen";
        mp["15"]="Fifteen";
        mp["16"]="Sixteen";
        mp["17"]="Seventeen";
        mp["18"]="Eighteen";
        mp["19"]="Nineteen";
        mp["20"]="Twenty";
        mp["30"]="Thirty";
        mp["40"]="Forty";
        mp["50"]="Fifty";
        mp["60"]="Sixty";
        mp["70"]="Seventy";
        mp["80"]="Eighty";
        mp["90"]="Ninety";
        mp["100"]="Hundred";
    }

    void getValue(string a){
        string hun="0";
        string ten="0";
        string one="0";
        if(a.size()==3){
            hun=a[0];
            ten=a[1];
            one=a[2];
        }else if(a.size()==2){
            ten=a[0];
            one=a[1];
        }else{
            one=a[0];
        }
        if(hun=="0" && ten=="0" && one=="0"){
            return;
        }
        if(hun=="0"){
        }else{
            answer.push_back(mp[hun]);
            answer.push_back(mp["100"]);
        }
        if(ten=="0"){
        }else if(ten=="1"){
            answer.push_back(mp[ten+one]);
            return;
        }else{
            answer.push_back(mp[ten+"0"]);
        }
        if(one!="0"){
            answer.push_back(mp[one]);
        }
    }

    void divid(string number){
        vector<string> temp;
        vector<string> name;
        string curr="";
        for(int i=number.size()-1;i>=0;i--){
            curr=number[i]+curr;
            if(curr.size()==3){
                temp.push_back(curr);
                curr="";
            }
        }
        if(curr!=""){
            temp.push_back(curr);
        }
        name.push_back("");
        for(int i=1;i<temp.size();i++){
            if(i==1){
                name.push_back("Thousand");
            }else if(i==2){
                name.push_back("Million");
            }else{
                name.push_back("Billion");
            }
        }
        for(int i=temp.size()-1;i>=0;i--){
            if(i==0){
                getValue(temp[i]);
            }else{
                getValue(temp[i]);
                if(temp[i]!="000"){
                    answer.push_back(name[i]);
                }
            }
        }
    }

    string numberToWords(int num) {
        fillMap();
        string result="";
        if(num==0){
            return "Zero";
        }
        string number=to_string(num);
        divid(number);
        for(int i=0;i<answer.size();i++){
            result+=answer[i];
            if(i!=answer.size()-1){
                result+=" ";
            }
        }
        return result;
    }
};

// Time Complexity - O(10)
// Space Complexity - O(25)
