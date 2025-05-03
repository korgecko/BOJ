#include <string>
#include <stack>

using namespace std;

string readInput();
void printResult(bool isPPAP);

void inputStack();

void popLastFourCharacters();

bool isPPAPPattern();

void makePPAPtoP();

bool isPPAPString(string input); 





// ── 2) 입력 함수 ────────────────────────────────────────
string readInput() {
    string s;
    cin >> s;
    return s;
}


// ── 3) 출력 함수 ────────────────────────────────────────
void printResult(bool isPPAP) {
    if (isPPAP) 
        cout << "PPAP\n";
    else 
        cout << "NP\n";
}

void inputStack(input)
{
    // 이 스택은 지금까지 처리한 문자들을 뒤에서부터 4개씩 검사하기 위한 용도입니다.
    stack<char> st; 

    for (char each_character : input) {
        st.push(each_character);
    }

    return 0;
}






{
    
    if (st.size() >=4)
    {
        
        char last4[4]; 

        for (int i = 3; i >= 0; --i) {
            last4[i] = st.top(); // 
            st.pop(); 
        }
        
    }
}

bool isPPAPPattern()
{
    return (fourChars[0] == 'P' &&
            fourChars[1] == 'P' &&
            fourChars[2] == 'A' &&
            fourChars[3] == 'P');
}


void makePPAPtoP()
{

}

bool isPPAPString(string input)
{

}