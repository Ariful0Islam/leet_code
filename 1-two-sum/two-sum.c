/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    int key;
    int val;
}HashEntry;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int hashSize = numsSize * 2;
    HashEntry* hashTable = (HashEntry*)calloc(hashSize, sizeof(HashEntry));
    int* occupied = (int*)calloc(hashSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int hashIdx = abs(complement) % hashSize;
        while (occupied[hashIdx]) {
            if (hashTable[hashIdx].key == complement) {
                result[0] = hashTable[hashIdx].val;
                result[1] = i;
                free(hashTable);
                free(occupied);
                return result;
            }
            hashIdx = (hashIdx + 1) % hashSize;  
}
    int insertIdx = abs(nums[i]) % hashSize;
        while (occupied[insertIdx]) {
            insertIdx = (insertIdx + 1) % hashSize;
        }
        hashTable[insertIdx].key = nums[i];
        hashTable[insertIdx].val = i;
        occupied[insertIdx] = 1;
    }
    free(hashTable);
    free(occupied);
    *returnSize = 0;
    return NULL;
}