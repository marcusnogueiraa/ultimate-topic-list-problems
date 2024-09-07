#include <bits/stdc++.h>

using namespace std;

ifstream fin("bcount.in");
ofstream fout("bcount.out");

struct SumSlot {
    int holsteins;
    int guernseys;
    int jerseys;
};

int main(){
    int n, q;
    fin >> n >> q;

    vector<SumSlot> prefix(n+1, {0, 0, 0});

    for(int i = 0; i < n; i++){
        int cow;
        fin >> cow;

        prefix[i+1] = prefix[i];

        if (cow == 1)
            prefix[i+1].holsteins++;

        if (cow == 2)
            prefix[i+1].guernseys++;

        if (cow == 3)
            prefix[i+1].jerseys++;
    }

    for(int i = 0; i < q; i++){
        int l, r;
        fin >> l >> r;
        l--; r--;
        fout << prefix[r+1].holsteins - prefix[l].holsteins << " ";
        fout << prefix[r+1].guernseys - prefix[l].guernseys << " ";
        fout << prefix[r+1].jerseys - prefix[l].jerseys << endl;
    }

    return 0;
}
