// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
vector<int> IDsOfSongs(int rideDuration, vector<int> songDurations)
{
// WRITE YOUR CODE HERE
    vector<int> r;
    int i, j, N=songDurations.size(), old0, old1, new0, new1;

    for(i=0; i<N-1; i++) {
        for(j=i+1; j<N; j++) {
            if(songDurations[i]+songDurations[j] == rideDuration-30) {
                if(r.size()) {

                    old0 = songDurations[r[0]];
                    old1 = songDurations[r[1]];

                    new0 = songDurations[i];
                    new1 = songDurations[j];

                    if(max(old0, old1) < max(new0, new1)) {
                        r[0] = i;
                        r[1] = j;
                    }
                } else {
                    r.push_back(i);
                    r.push_back(j);
                }
            }
        }
    }

    return r;
}
// FUNCTION SIGNATURE ENDS