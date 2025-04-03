#include <iostream>
using namespace std;

void fractional_knapsack(int w[], int p[], int c, int size)
{
  float cost[size];
  for (int i = 0; i < size; i++)
  {
    cost[i] = static_cast<float>(p[i]) / w[i];
  }

  // sort in decending
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (cost[i] < cost[j])
      {
        swap(cost[i], cost[j]);
        swap(w[i], w[j]);
        swap(p[i], p[j]);
      }
    }
  }

  int i = 1;
  int profit = 0;
  while (i <= size && c > 0)
  {
    if (w[i] <= c)
    {
      c = c - w[i];
      profit = profit + p[i];
    }

    if (w[i] > c && c != 0)
    {
      profit = profit + ((cost[i] * w[i]) / c);
    }
    i = i + 1;
  }
  cout << "Maximum profit: " << profit << endl;
}

int main()
{
  int p[] = {10, 5, 15, 7, 6, 18, 3};
  int w[] = {2, 3, 5, 7, 1, 14, 1};
  int capacity = 15;
  int size = sizeof(p) / sizeof(p[0]);
  fractional_knapsack(w, p, capacity, size);

  return 0;
}