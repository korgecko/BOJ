#include <iostream>
#include <string>
#include <stack>
#include <array>

using namespace std;

// 스택에서 마지막 네 글자를 꺼내서 characterBuffer에 저장
// 꺼낼 수 있으면 true, 그렇지 않으면 false
bool popLastFourCharacters(stack<char>& characterStack, array<char,4>& characterBuffer)
{
    // 스택에 4개 미만 원소밖에 없으면 pop 4번 할 수 없음.
    if (characterStack.size() < 4) 
    {
        return false;
    }

    // size() 4 이상일 때 아래 로직 실행
    // characterBuffer[0]부터 [3]까지 총 4칸짜리 메모리를 확보
    for (int index = 3; index >= 0; --index)
    {
        // 스택의 가장 위(마지막) 글자를 characterBuffer[index]에 저장
        characterBuffer[index] = characterStack.top(); 
        // 그 글자를 스택에서 제거
        characterStack.pop();
    }
    // 반복이 끝나면 characterBuffer[0]에는 가장 오래된 글자가,
    // characterBuffer[3]에는 가장 최신 글자가 들어 있습니다.
    return true;
}

// 배열에 담긴 네 글자가 정확히 'P','P','A','P'인지 비교
bool isBufferPPAPPattern(const array<char,4>& characterBuffer)
{
    return (characterBuffer[0] == 'P' &&
            characterBuffer[1] == 'P' &&
            characterBuffer[2] == 'A' &&
            characterBuffer[3] == 'P');
}

// PPAP 문자열인지 판별
bool isPPAPString(string inputString)
{
    stack<char> characterStack;
    array<char,4> characterBuffer;

    // 문자열을 하나씩 스택에 넣으면서 검사
    for (char currentCharacter : inputString) {
        characterStack.push(currentCharacter);

        // 네 글자 꺼낼 수 있으면 시도
        if (popLastFourCharacters(characterStack, characterBuffer)) {
            if (isBufferPPAPPattern(characterBuffer)) {
                // PPAP 패턴이면 'P' 하나로 축약
                characterStack.push('P');
            } else {
                // 패턴이 아니면 다시 복원
                for (char bufferedChar : characterBuffer) {
                    characterStack.push(bufferedChar);
                }
            }
        }
    }

    // 최종적으로 스택에 'P' 한 글자만 남아있으면 PPAP
    return (characterStack.size() == 1 && characterStack.top() == 'P');
}

int main()
{
    // 1) 입력 받기
    string inputString;
    cin >> inputString;

    // 2) PPAP 판별
    bool isPPAP = isPPAPString(inputString);

    // 3) 결과 출력
    if (isPPAP) {
        cout << "PPAP\n";
    } else {
        cout << "NP\n";
    }

    return 0;
}