class Solution {
public:
    bool isValid(string s) {
        stack<char> inputs;
		unordered_map<char, char> parentheses = {
			{')','('},
			{']','['},
			{'}','{'},
		};
		for (auto &ch : s)
		{
			switch (ch)
			{
			case '(':
			case '[':
			case '{':
				inputs.push(ch);
				break;
			case ')':
			case ']':
			case '}':
				if (inputs.empty() || inputs.top() != parentheses[ch])
					return false;
				inputs.pop();
				break;
			default:
				return false;
			}
		}
		return inputs.empty();
    }
};
