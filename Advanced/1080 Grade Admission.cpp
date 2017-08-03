#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct Applicant
{
    int id;
    int ge;
    int gi;
    bool isAdmitted;
    int quota[5];
};

struct LastGrade
{
    int ge;
    int gi;
};

Applicant applicants[40000];
int capacity[100];
map< int, vector<int> > result;
map< int, LastGrade > lastGrade;

void input(int n, int m, int k);
bool compare(Applicant a, Applicant b)
{
    if(a.ge + a.gi == b.ge + b.gi)
        return a.ge > b.ge;
    return a.ge + a.gi > b.ge + b.gi;
}
void admit(int n, int m, int k);

int main(int argc, char const *argv[])
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    input(n, m, k);
    sort(applicants, applicants + n, compare);
    admit(n, m, k);
    for(int i = 0; i < m; i++)
    {
        if(result[i].size() == 0)
            printf("\n");
        else
        {
            for(int j = 0; j < result[i].size() - 1; j++)
                printf("%d ", result[i][j]);
            printf("%d\n", result[i][result[i].size() - 1]);
        }
    }
    return 0;
}

void input(int n, int m, int k)
{
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &capacity[i]);
        lastGrade[i].ge = lastGrade[i].gi = 101;
    }
    for(int i = 0; i < n; i++)
    {
        applicants[i].id = i;
        applicants[i].isAdmitted = false;
        scanf("%d %d", &applicants[i].ge, &applicants[i].gi);
        for(int j = 0; j < k; j++)
            scanf("%d", &applicants[i].quota[j]);
    }
}

void admit(int n, int m, int k)
{
    for(int i = 0; i < n; i++)//Stu
    {
        if(!applicants[i].isAdmitted)
        {
            for (int j = 0; j < k; j++)//Quota
            {
                int schoolId = applicants[i].quota[j];
                if (result[schoolId].size() < capacity[schoolId])
                {
                    result[schoolId].push_back(applicants[i].id);
                    applicants[i].isAdmitted = true;
                    if(lastGrade[schoolId].ge + lastGrade[schoolId].gi > applicants[i].ge + applicants[i].gi
                            || (lastGrade[schoolId].ge + lastGrade[schoolId].gi == applicants[i].ge + applicants[i].gi
                                && applicants[i].ge < lastGrade[schoolId].gi))
                    {
                        lastGrade[schoolId].ge = applicants[i].ge;
                        lastGrade[schoolId].gi = applicants[i].gi;
                    }
                    break;
                }
                else
                {
                    if(lastGrade[schoolId].ge == applicants[i].ge && lastGrade[schoolId].gi == applicants[i].gi)
                    {
                        result[schoolId].push_back(applicants[i].id);
                        applicants[i].isAdmitted = true;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        if(result[i].size() > 0)
            sort(result[i].begin(), result[i].end());
    }
}