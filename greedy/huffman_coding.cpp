class Node {
public:
  char c;
  int freq;
  Node *left;
  Node *right;

  Node(char c, int freq, Node *left = NULL, Node *right = NULL) {
    this->c = c;
    this->freq = freq;
    this->left = left;
    this->right = right;
  };
};

struct cmp {

   bool operator()(Node* l, Node* r)
   
   {
   return (l->freq > r->freq);
   }
};

class Solution
{
	public:
	     
	   void printNode(Node *node, string str,vector<string>&v) {
                if (node->c != '$') {
                  v.push_back(str);
                  return;
                }
                printNode(node->left, str + "0",v);
                printNode(node->right, str + "1",v);
        }
        
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
            priority_queue<Node*, vector<Node*>, cmp> pq;
            
            for (int i = 0; i < N; i++)
              pq.push(new Node(S[i], f[i]));
            
            while (pq.size() > 1) {
              Node *l = pq.top();
              pq.pop();
              Node *r = pq.top();
              pq.pop();
            
              Node *node = new Node('$', l->freq + r->freq, l, r);
              pq.push(node);
            }
            
            vector<string>v;
            printNode(pq.top(),"",v);
            
            return v;
		}
};