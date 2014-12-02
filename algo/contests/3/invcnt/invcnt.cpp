#include <fstream>

uint32_t a, b;
uint32_t cur = 0;
uint32_t next_rand() {
    cur = cur * a + b;
    return cur >> 8;
}

uint64_t inner_sort(uint32_t *a, uint32_t *tmp, uint32_t l, uint32_t r);
uint64_t merge_sort(uint32_t a[], uint32_t n) {
    return inner_sort(a, new uint32_t[n], 0, n - 1);
}

uint64_t merge(uint32_t *a, uint32_t *tmp, uint32_t l, uint32_t r, uint32_t m);
uint64_t inner_sort(uint32_t *a, uint32_t *tmp, uint32_t l, uint32_t r) {
    uint32_t mid;
    uint64_t cnt = 0;
    if (r > l) {
        mid = l + (r - l) / 2;
        cnt = inner_sort(a, tmp, l, mid);
        cnt += inner_sort(a, tmp, mid + 1, r);
        cnt += merge(a, tmp, l, r, mid + 1);
    }
    return cnt;
}

uint64_t merge(uint32_t *a, uint32_t *tmp, uint32_t l, uint32_t r, uint32_t m) {
    uint64_t cnt = 0;
    uint32_t i = l;
    uint32_t j = m;
    uint32_t k = l;
    while (i <= m - 1 && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        }
        else {
            tmp[k++] = a[j++];
            cnt += (m - i);
        }
    }
    while (i <= m - 1) {
        tmp[k++] = a[i++];
    }
    while (j <= r) {
        tmp[k++] = a[j++];
    }
    for (i = l; i <= r; i++) {
        a[i] = tmp[i];
    }
    return cnt;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::ifstream cin("invcnt.in");
    std::ofstream cout("invcnt.out");

    uint32_t n, m;
    cin >> n >> m;
    cin >> a >> b;
    uint32_t nums[1000000];
    for(uint32_t i = 0; i < n; i++)
    {
        nums[i] = next_rand() % m;
    }
    cout << merge_sort(nums, n) << std::endl;
    return 0;
}
