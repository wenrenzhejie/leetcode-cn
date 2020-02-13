
//////////////////////////////////////////////////////////////////////////
//bool isLine(vector<int>& a, vector<int>& b, vector<int>& c)
//{
//	long long tmp1 = ((long long)a[0] - b[0]) * ((long long)a[1] - c[1]);
//	long long tmp2 = ((long long)a[0] - c[0]) * ((long long)a[1] - b[1]);
//	if (tmp1 == tmp2) return true;
//	return false;
//}
//
//int maxPoints(vector<vector<int>>& points)
//{
//	if (points.size() < 3) return points.size();
//	int res = 0;
//	for (int i = 0; i < points.size(); i++)
//	{
//		int cnt1 = 1;
//		for (int j = i + 1; j < points.size(); j++)
//		{
//			if (points[i] == points[j])
//			{
//				cnt1++;
//				res = max(res, cnt1);
//				continue;
//			}
//			int cnt2 = 1;
//			for (int k = j + 1; k < points.size(); k++)
//			{
//				if (points[i] == points[k] || points[j] == points[k]) cnt2++;
//				else if (isLine(points[i], points[j], points[k])) cnt2++;
//			}
//			res = max(res, cnt1 + cnt2);
//		}
//	}
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
bool cmp(vector<int>& a, vector<int>& b)
{
	if (a[0] != b[0]) return a[0] < b[0];
	else return a[1] < b[1];
}

bool isLine(vector<int>& a, vector<int>& b, vector<int>& c)
{
	long long tmp1 = ((long long)a[0] - b[0]) * ((long long)a[1] - c[1]);
	long long tmp2 = ((long long)a[0] - c[0]) * ((long long)a[1] - b[1]);
	if (tmp1 == tmp2) return true;
	return false;
}

int maxPoints(vector<vector<int>>& points) 
{
	if (points.size() < 3) return points.size();
	sort(points.begin(), points.end(), cmp);

	int ans = 2, count1 = 1, count2 = 1;
	for (int i = 0; i < points.size() - 2; i++) 
	{
		count1 = 1;
		while (i < points.size() - 3 && points[i + 1][0] == points[i][0] && points[i + 1][1] == points[i][1]) 
		{
			count1++;
			i++;
		}
		for (int j = i + 1; j < points.size() - 1; j++) 
		{
			count2 = 1;
			while (j < points.size() - 2 && points[j + 1][0] == points[j][0] && points[j + 1][1] == points[j][1]) 
			{
				count2++;
				j++;
			}
			int tmp = count1 + count2;
			for (int k = j + 1; k < points.size(); k++) {
				if (isLine(points[i], points[j], points[k])) tmp++;
			}
			ans = ans > tmp ? ans : tmp;
		}
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& points)
{
	return maxPoints(points);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

