#include <iostream>
#include <queue>
using namespace std;

class minHeapNode
{   
    public :
    char data;
    int freq;
    minHeapNode*left;
    minHeapNode*right;

    minHeapNode(char c, int f)
    {
        data = c;
        freq = f;
        left = NULL;
        right = NULL;
    }

};

class compare
{
    public:
    bool operator()(minHeapNode*a, minHeapNode*b)
    {
        return (a->freq > b->freq);
    }
};

void printcodes(minHeapNode* root, string s)
{
    if(root==NULL) return;
    if(root->data!='$') 
    {
        cout<<root->data<<" : "<<s<<endl;
    }
    printcodes(root->left,s+"0");
    printcodes(root->right,s+"1"); t
}

void HuffmanCode(char data[],int freq[], int n)
{
    minHeapNode* left;
    minHeapNode* right;

   

    priority_queue<minHeapNode*,vector<minHeapNode*>,compare>pq;
        for(int i=0; i<n; i++)
    {
        pq.push(new minHeapNode(data[i],freq[i]));
    }

    while(pq.size()!=1) 
    {   
       
        left = pq.top(); 
        pq.pop();
        right = pq.top();
        pq.pop();

        minHeapNode*temp = new minHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        pq.push(temp);
    }

    printcodes(pq.top(),"");
}

int main()
{
    char data[] = {'a','b','c','d','e','f'};
    int freq[] = {5,9,12,13,16,45};
        cout<<"The Generated Huffman Codes are : "<<endl;
    HuffmanCode(data,freq,6);
}