class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if ( start.compare( end ) == 0 ) {
            return 0;
        }
        unordered_set<string> mp(bank.begin(),bank.end());
        if( mp.find(end) == mp.end() ){
            return -1;
        }
        queue<pair<string,int>> q;
        q.push( {start,0} );
        string t = "ACGT";
        
        while ( ! q.empty() ) {
            string s = q.front().first;
            int l = q.front().second;
            q.pop();
            if ( s.compare( end ) == 0 ) {
                return l;
            }
            for (int i = 0 ; i < 8 ; i++ ) {
                char c = s[i] ; 
                for (int j = 0 ; j < 4 ; j++ ) {
                    s[i] = t[j] ;
                    if( mp.find( s ) != mp.end() ) {
                        q.push( { s,l+1 } );
                        mp.erase( s );
                    }
                }
                s[i] = c;
            }
        }
        
        return -1;
    }
};