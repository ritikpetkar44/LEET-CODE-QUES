class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL or head->next==NULL or head->next->next==NULL) return {-1,-1};
        vector<int> help;
        int idx=1;
        ListNode *prev=head,*curr=head->next,*next=curr->next;
        while(next){
            int a=prev->val,b=curr->val,c=next->val;
            if((b>a and b>c) or (b<a and b<c)) help.push_back(idx);
            prev=curr;
            curr=next;
            next=next->next;
            idx++;
        } 
        if (help.size()<2) return {-1,-1};
        int minDiff=INT_MAX;
        for(int i=1;i<help.size();i++) minDiff=min(minDiff,help[i]-help[i-1]);
        int maxDiff=help[help.size()-1]-help[0];
        return {minDiff,maxDiff};
    }
};