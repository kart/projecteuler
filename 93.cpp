#include <iostream>
#include <stack>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <cstring>

#define MUL	-10000001
#define DIV	-10000002
#define ADD	-10000003
#define SUB	-10000004

#define IS_OPERATOR(VAL)	((VAL >= SUB) && (VAL <= MUL))

float possibilities[] = {0, 1., 2., 3., 4., 5., 6., 7., 8., 9., MUL, DIV, ADD, SUB};
bool used[14];
int num_used, op_used;

using namespace std;

float array[7];
int cumul[10000][4000];

int signature(float arr[])
{
	int	val = 0;
	float	carr[7];

	memcpy(carr, arr, sizeof(carr));
	sort(carr, carr + 7);
	for (int i = 3; i < 7; i++)
		val = val * 10 + (int)carr[i];
	return val;
}

float do_op(float oper, float op1, float op2)
{
	if ((float) MUL == oper)
		return op1 * op2;
	if ((float) DIV == oper)
		return op1 / op2;
	if ((float) ADD == oper)
		return op1 + op2;
	if ((float) SUB == oper)
		return op1 - op2;
	assert(0);
	return -1.0; // unreachable
}

float eval_postfix(float arr[])
{
	stack<float>	stk;

	assert(!IS_OPERATOR(arr[0]));
	assert(!IS_OPERATOR(arr[1]));
	stk.push(arr[0]);
	stk.push(arr[1]);
	for (int i = 2; i < 7; i++)
	{
		if (!IS_OPERATOR(arr[i]))
			stk.push(arr[i]);
		else
		{
			if (stk.empty()) return -1;
			float op2 = stk.top(); stk.pop();
			if (IS_OPERATOR(op2)) return -1;
			if (stk.empty()) return -1;
			float op1 = stk.top(); stk.pop();
			if (IS_OPERATOR(op1)) return -1;
			stk.push(do_op(arr[i], op1, op2));
		}
	}
	if (stk.size() != 1)
		return -1;
	return stk.top();
}

void generate(int pos)
{
	if (pos < 2)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (used[i])
				continue;
			array[pos] = possibilities[i];
			used[i] = true;
			num_used++;
			generate(pos + 1);
			num_used--;
			used[i] = false;
		}
	} else if (pos < 7)
	{
		int	st, end;
		bool	use_num, use_op, use_both;

		assert(num_used >= 2);
		use_num = (num_used < 4);
		use_op = (op_used < 3);
		use_both = (use_num && use_op);
		st = (use_both || use_num) ? 1 : 10;
		end = (use_both || use_op) ? 14 : 10;
		assert(st < end);
		for (int i = st; i < end; i++)
		{
			if (i < 10 && used[i])
				continue;
			array[pos] = possibilities[i];
			if (i < 10)
			{
				used[i] = true;
				num_used++;
			} else
				op_used++;
			generate(pos + 1);
			if (i < 10)
			{
				used[i] = false;
				num_used--;
			} else
				op_used--;
		}
	} else
	{
		float rv = eval_postfix(array);
		assert((int)rv <= 3024);
		if ((0.0 < rv) && (!isinf(rv)) && (ceil(rv) == rv))
		{
			int val = signature(array);
			assert(val >= 1000 && val <= 9999);
			cumul[val][(int)rv] = 1;
		}
	}
}

void test()
{
	float	arr1[] = {4., 1., 3., ADD, MUL, 2., DIV};
	float	arr2[] = {4., 3., 1., 2., DIV, ADD, MUL};
	float	arr3[] = {4., 2., 3., ADD, MUL, 1., SUB};
	float	arr4[] = {3., 4., 2., 1., ADD, MUL, MUL};
	assert(8 == eval_postfix(arr1));
	assert(14 == eval_postfix(arr2));
	assert(19 == eval_postfix(arr3));
	assert(36 == eval_postfix(arr4));
}

//Ans = 1258 ; Count = 51
int main()
{
	int		max = 1, maxval;
	test();

	generate(0);
	for (int i = 1000; i <= 9999; i++)
	{
		int 		j = 1;

		for (; cumul[i][j] && (j <= 3024); j++);
		j--;
		if (j > max)
		{
			max = j;
			maxval = i;
		}
	}
	cout << maxval << " = " << max << endl;
	return 0;
}
