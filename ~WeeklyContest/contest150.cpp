#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<string>

using namespace std;



class Solution1160 {
public:
	int countCharacters(vector<string>& words, string chars) {
		vector<int> v(26, 0);
		for (auto i : chars)
		{
			++v[i - 'a'];
		}

		int res = 0;
		for (auto i : words)
		{
			int len = i.size();
			vector<int> t = v;
			bool f = false;
			for (auto j : i)
			{
				if (--t[j - 'a'] < 0)
				{
					f = true;
					break;
				}
			}

			if (!f) res += len;
		}

		return res;
	}
};


/////////////////////////////////////////////////////////////////////////


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution1161 {
public:
	int maxLevelSum(TreeNode* root) {
		if (!root) return 0;
		if (!root->left && !root->right) return root->val;
		queue<TreeNode*> q;
		q.push(root);
		int level = 1;
		int global = root->val;
		int glolev = 1;
		while (!q.empty())
		{
			int len = q.size();
			int cur = 0;
			for (int i = 0; i < len; ++i)
			{
				TreeNode* t = q.front();
				q.pop();
				cur += t->val;
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			if (cur > global)
			{
				global = cur;
				glolev = level;
			}
			++level;
		}

		return glolev;
	}
};


/////////////////////////////////////////////////////////////////////////


class Solution1162 {
public:
	int maxDistance(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<pair<int, int>> zeros, ones;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] == 1)
				{
					ones.push_back({ i,j });
				}
				else
				{
					zeros.push_back({ i,j });
				}
			}
		}

		if (ones.empty() || zeros.empty()) return -1;

		int res = 0;
		for (auto i : zeros)
		{
			int cur = m + n;
			for (auto j : ones)
			{
				//if (distance(i.first, i.second, j.first, j.second) < cur)
				//{
				//	//cout<<" " << i.first << " " << i.second << " " << j.first << " " << j.second <<endl;
				//	cur = distance(i.first, i.second, j.first, j.second);
				//}

				cur = min(cur, distance(i.first, i.second, j.first, j.second));

			}

			res = max(res, cur);
		}
		return res;
	}

	int distance(int x1, int y1, int x2, int y2)
	{
		return abs(x1 - x2) + abs(y1 - y2);
	}

};


/////////////////////////////////////////////////////////////////////////

//class Solution {
//public:
//	string lastSubstring(string s) {
//		if (s.empty()) return "";
//		set<string> t;
//		vector<int> v(s.size(), 0);
//		helper(t, s, v, "");
//
//		vector<string> res(t.begin(), t.end());
//		sort(res.begin(), res.end());
//
//		for (auto i : res)
//			cout << i << " ";
//		cout << endl;
//	
//
//		return res.back();
//
//	}
//
//	void helper(set<string>& t, string& s,vector<int>& v,string cur)
//	{
//		if (!cur.empty() && t.count(cur) == 0)
//		{
//			t.insert(cur);
//		}
//		for (int i = 0; i < s.size(); ++i)
//		{
//			if (v[i] == 1) continue;
//			v[i] = 1;
//			helper(t, s, v, cur += s[i]);
//			v[i] = 0;
//		}
//
//	}
//
//};


class Solution1163 {
public:
	string lastSubstring(string s) {
		if (s.empty()) return "";

		vector<int> v(26, 0);
		for (auto i : s)
		{
			if (v[i - 'a'] == 1) continue;
			v[i - 'a'] = 1;
			if (i == 'z') break;
		}

		char c = 'a';
		for (int i = v.size() - 1; i >= 0; --i)
		{
			if (v[i] == 1) { c = 'a' + i; break; }
		}

		//set<string> t;
		//vector<string> res;
		//helper(s, res, c);
		
		string res;
		//helper(s, res, c);


		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != c) continue;
			for (int j = 1; j < s.size() - 1; j++)
			{
				//t.insert(str.substr(i, i + j));
				//t.push_back(str.substr(i, i + j));
				/*string cur = str.substr(i, i + j);
				if (t < cur)t = cur;*/
				res = max(res, s.substr(i, i + j));
			}
		}

		res = max(res, s);
		//res.push_back(s);
		//t.insert(s);
		//vector<string> res(t.begin(), t.end());
		//sort(res.begin(), res.end());


		//for (auto i : res)
		//	cout << i << " ";
		//cout << endl;


		//return res.back();
		return res;
	}

	//void helper(string& str, set<string>& t,char c)
	//void helper(string& str, vector<string>& t, char c)
	void helper(string& s, string& res, char c)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != c) continue;
			for (int j = 1; j < s.size() - 1; j++)
			{
				//t.insert(str.substr(i, i + j));
				//t.push_back(str.substr(i, i + j));
				/*string cur = str.substr(i, i + j);
				if (t < cur)t = cur;*/
				res = max(res, s.substr(i, i + j));
			}
		}
	}

};


//class Solution {
//public:
//	string lastSubstring(string s) {
//		string ans;
//		int index = 0;
//		for (int j = 'z'; j >= 'a'; j--)
//			for (int i = 0; i<s.size(); i++)
//				if (s[i] == j&&i >= index)
//					ans += j, index = i;
//		return ans;
//	}
//};
//
//
//
//
//int main()
//{
//	Solution n;
//	//string s = "pgtrdjdpscrwjifnrcttyruighgygsuvlhxpckkeahrupvnhlnpulyogsbktcuxnmnbmgadksxdjunqvmzyujynwzevtstjvzkddxjjmbgxfueteeuktvcbvypbdnzostbwxmxdwomguuymexfrrwuvuglgwmmwpkrqrpuzvjujksdwopsqlsrfgyzhymfgejuwhyvoqoxluvsdnmkglypoozrcgnzchpurezauixujddjjawqiaasvhrhfbhsqutgskudpcbqkkrcagrtalnsecxmlbiysgabvjbwpfufiwqdsnwbutashtejpmcypfztbgzuxwfcpkwdzhvfxbtvdvdaufjpqgfgxufhsopvwmgekcjejdlgxtdghmyzvopqkdzpuudyunnafvaeyshluuujkqncyigweelxmvgiaegonqmouaxwaqxhnnvaeuppsritdsymdwonbooswiolhbacpnehyvbhekxqxuvpnaxrfgeyixmurlgszqrotqynvtlbpjhhwdkbneiutmwutiyqegkxsrgldqvziysvihgbplhiumonlzlfzbuavbygmltdnfwjbspfpmzkfryjjpswihwixmbeodfpnmytccdvjnctzkxuqrvgjehodfdhpconhfpnatzzxyqkzjttgnwvxcfwyhlajvuhjonbpkvbbahlbybvvnhrwnnpnagtnnqcewzdzsxjgfoqbipohzsgpmyhqgvvnffjumirbhpbfletvcglthgwdvkgczucreovnfpbugyzuugqodpgsylfwyjucfnxjbghurnrkkuwsjfxeoxyzvltwhzyuechbfwstfovqgxngcwsmqsbzasrfrdvjcgedacvviihnzlijbaotpkvzmfejtfsnljthmzfhsrtieqlfhuatdwhcvsoxyphqsoxaqiqjcbuldswtjsukvcoowyfgmixswlyvkllvdtnerfisymrwgtfleupfxxswdlhvioeilstdlqfckoxpohcgnfannhbeeyzthhmszdphsbhjhxbwmjcknyrcsxgxcgnrvqnrlpqqwilhradmbowdvpusmombllpjikbuokakqzovmtmanaavururxjjxvrdnwabfwchkscmmmyixmjtogqgowbqlymnjcalxkmolmhyalvaftbcsidbmyfxshzdbwsfkvlnunvxzadljqngnnhjmlhfpmwnhvvwaokxxyfslhgggpjnhkyzdqgjdsrtaohqaryixzpyrkjumnphvfpsldrcjhxqjisogvybchagdnoezpvehagcqxarruqncmjifvxxvpbsygkzttmnykeptvbxmjsewbppcciomuyuowzbankzklnnxmnxiztfpfcnddaghyuxgaxmgphspocmpcucxkazeakifbsvnatqcvbeywbxsocgyxiawvmljwmokhbpzvijuckbqrjsdtntlriqgyjznvkkeoszsqsonjlsmxhawqqbdwixvnyemiypirwnoyhvfhbbbkcuyuuepobvrspotbbuvtmpykalufsvizvcelblhokldaymsgqasbobwyxnmcqvzqyldgmimsolloudxkjmiyekaiierxwwflmanqkovzxewrrfipzrclqvedftsuswanhfbcmjigxuxaguasfjypjjrgddnwnrfoazbvezxopumretyqfzqyosmvqjpqnuodylrkucrbhtrljryryewvfbnfwjldgjidvucotlvnsvqyjqwfmqhydttjaapqfdmvcytqpcjkqqrhwfiimbvlkvnvtghrggkjppaduhqpdneeejpqrxbnnenvobcgreldbnzpzrwxvkscywgekcnqnkgngokryvfgthpeggwroimsrwwvfmburaaqrzcmtctfxgrlhzbgixfkdjuerowuvtkmawtsrjzucrniwyzeauuizmfdlufwzqotupmykssvwaqljbiegvbonhqaekpeknpvkzgerjljgridlosexgtjkxnnjcqiahuvwvewsjmxbdhsemaoqsfsgxwghtskfxxxtohbqkascghktyxjeznuhguhvkhkhrgxvfjvktljkvmvkrikybfhjrleqxrwvyevynaprnumwpoazwmbevifrcbcckwmhcqrzgyywxlvxjmckmrfitvkelvoubqmflpmuhlwcjtcokvourxueatywmbsgbtcqzmekogznpbqsahgubnsfzfrvlgqvdsqcjptjkztcwbdciaivtwzavpzxgnbtscpzmffbwzezpijzcxnehhecsdyxabdupyqrfxywcikihubgfwrllhdmampqzewshiumisbuabzuthodmfjczwvwwbxbtadhhqqyqdzrfgzlbtlrtayrflxuehrxmggtbglsijmqiozpaydqxcewzizkdauybxbxhekppdxwnrwuchqotbsvatsxallqoatgdlarcoakioexnkugtpdldgzwnjmrdxtaheygwqmesdtinktgfxwsdibsyqyqdypwpzxucwefnzhfwjcnecbhtpuhcmvnyczwlozxlnsiizeteykfiitgyfqjbsoxvtumabgjhaquojutgxzqniiiisqhixjpcnhvopknagkmbuyqbbhlgaqhrnedonfsinfpywjvncbefkdwiidrmjtfunjhbcyvwnbiffildglmcspbmumhyewizqgfwuvbqawruppyjfkmthxpocpbduzqvecdapdjmiuvzduavdasropcdfmrzdfwkisetbznqubivoqkzvxhiuxowfmrsuevnllosjzzeajuxvvayugkzolddxbhyetzqkrxeyomyjidrculppuxxyuswfzkawloetbximriowohrduwpecmczgurxippfecsdrpybwjhbutwgqqrzckigaqevdazolffbffhpmklobchtddrbaqwfddkizyyhpowbgjiswezvhljhcjmetduxyawxjlzthhuplzwidbcbckqxmnitrniupkrqmzxdyctxgaagizoxgpjcedyuewibyalsvlshpngreerfzrqfloevdearlhcdwmxyjoqozxljgbgnccdefycdrqseaqsybwkvzeeccvkpmvpumlhjhsbaenzpbswpcgnxcvkdwllgwubibjaoiadzndfcodoaczxlugycuhdnkcvxjfzptwutlocwctpdfzfkygjrqxavotfrdlmazcfyjsrffzpnzfmuywpjkgywelrhiejhzeuagmlnefnmpscwcpjlcwbkgqwmohylgekxctqmitgtialbugksfirpemtpeixcypilupvlyppqalshwfeeqsqvjorfmpixdzlbiuxmshemapxjrmxhzkrquumpoiqzdgqldzfqohqyfhjeucjsuvjqtlyopxvgauncwthkcuxrtnsobcpkohuygbgltmgogainwmgebuiesejbwgajeaxhbegysmgfhiqdbpgbzsirzjntnfcvjlrqrstbxgznqzzzlxmkwbpvocrzeyquurrjnoblqeohyqfjhmsakicpazwvbvoouiytydwerlxzffwljqtqcwzytmdbpfloyfoixpqivuatqunngyazxvxdnyxhuahilvwnnmhimgxyvtopgsspwzubozebxefsmvsccyiykpoldfmmrnaywhbkcpgjvhuoclwxkxlbszuasmhynflhldmkkecgxjliseppoqrieqwtjkqidksvxctztcpjgedhsgnarqwyliuwbioarpurqdgubcowdepthbqxrtaxzatwzzoxbyuvinokysodoumpztnvcwtsbicuvtvqxszfdpcfdofzkcyqtojcywcsbijvsgitjbdpmqowvvdtllgdbdotqmkgklpizyltljyfdvmluinspznkutjlhwsfudbwiyrmisaqgjlhcneqnoeqrmsztwdkhjqorbfxpkzkihjpgdggwbajszidcvufnjyqxwwxglawjvneegoxztrcyjqlduczzhgdlesnaeyialxfhtcgwkxjcdsllpqwurenryothdqzdbjmppjyvwzxobkvlrxjytmpklararqdqjjnblxaliqhjvtbzysfkbhroccnlwnslpsvkarenxfezocpdocgamvufzcfjkxijwybwgbfmnnwuuunsoupaxbylxggremxxakntirsqjwkyxkldqokrlwevrvoovoekhesvxmbnycclrdhrzzbovalhtnzdhfuyatdgeyazstiovogkiuuvsjvvofvrfwyoxydkgkvhporcxccrlcecgqakknogwyemwcfmokuflsskyevbdkmmumftzcpdonagopprxcmwwuarqxbxglrnprstubwfjmxpwdsribxcglhhzthhajimjawanewsqmwifzndqwojclkdilkisapeegpeixshskpfdnsbmfjiojelllsvuquupkwvnkgfdwreabvhyswnsnsdofccebjqmawlkqbzcrxqcvargeqvruhgypqcfbltnhswzjbjayqglgsyttnvpxrjbbotzcmoscbykzxoqoqkooycfiviewtmpyzzpicglhsydafzdzresxjeqhahsukeprzooumbltzxhmqktoypcjenuqqlkpwtvyscfcxcodnokzxpcjlimqmeltiipawblteiyaftlvefhrglstuwupkfvjzhrlvejljfahcenhnsqmmcfpnbtwrkukzncabvgyvvfqhsairahkulbejckkoapagatvkhceqswlpzijcwddrooijdcircayscwmordpckluyryrguednmhzleeklgggqujqeobgesjdbpuueenraljjecjxssdosskkbhrnykrfvumazfcjalcttxewlxiwtsojrmeakgzkwympgkdrshbiaamlwwwvacewcjgaruzmcpblpgqdyykxjyybhwwgowlcsliiitgffqdfprvrrf";
//	string s = "abab";
//	cout << n.lastSubstring(s) << endl;
//
//	return 0;
//}

