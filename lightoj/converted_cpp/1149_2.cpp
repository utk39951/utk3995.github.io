// A C++ program to find maximal Bipartite matching.
#include &lt;iostream&gt;
#include &lt;string.h&gt;
using namespace std;

// M is number of applicants and N is number of jobs
int M,N;
bool bpGraph[1000][1000];
// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(int u, bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v = 0; v &lt; N; v++)
    {
        // If applicant u is interested in job v and v is
        // not visited
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true; // Mark v as visited

            // If job &apos;v&apos; is not assigned to an applicant OR
            // previously assigned applicant for job v (which is matchR[v])
            // has an alternate job available.
            // Since v is marked as visited in the above line, matchR[v]
            // in the following recursive call will not get job &apos;v&apos; again
            if (matchR[v] &lt; 0 || bpm(matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

// Returns maximum number of matching from M to N
int maxBPM()
{
    // An array to keep track of the applicants assigned to
    // jobs. The value of matchR[i] is the applicant number
    // assigned to job i, the value -1 indicates nobody is
    // assigned.
    int matchR[N];

    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));

    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u &lt; M; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        // Find if the applicant &apos;u&apos; can get a job
        if (bpm( u, seen, matchR))
            result++;
    }
    return result;
}

// Driver program to test above functions
int main()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin&gt;&gt;t;
    int cas=1;
    while (t--){
        cin&gt;&gt;M;
        int a[M];
        for (int i=0;i&lt;M;i++) {
            cin&gt;&gt;a[i];
        }
        cin&gt;&gt;N;
        int b[N];
        for (int i=0;i&lt;N;i++){
            cin&gt;&gt;b[i];
        }
        memset(bpGraph,0,sizeof(bpGraph));
        for (int i=0;i&lt;M;i++){
            for (int j=0;j&lt;N;j++){
                if (b[j]%a[i]==0)
                    bpGraph[i][j]=1;
            }
        }
        /*for (int i=0;i&lt;n;i++){
            cout&lt;&lt;a[i]&lt;&lt;" : ";
            for (int j=0;j&lt;graph[i+1].size();j++){
                cout&lt;&lt;graph[i+1][j]&lt;&lt;"  ";
            }
            cout&lt;&lt;endl;
        }
        cout&lt;&lt;endl&lt;&lt;endl;*/
        cout&lt;&lt;"Case "&lt;&lt;cas++&lt;&lt;": "&lt;&lt;maxBPM()&lt;&lt;endl;
    }
    return 0;
}




