string a, b;

void string_add(){
    string s = a, x = b, temp = "";
    reverse(s.begin(), s.end());
    reverse(x.begin(), x.end());

    int carry = 0;
    for(int i=0; i<s.size() || i<x.size(); i++){
        int sum = carry;
        if(i<s.size()) sum+=s[i]-'0';
        if(i<x.size()) sum+=x[i]-'0';

        temp += sum%10+'0';
        carry = sum/10;
    }

    if(carry) temp += carry+'0';

    reverse(temp.begin(), temp.end());
    a = temp;
}
