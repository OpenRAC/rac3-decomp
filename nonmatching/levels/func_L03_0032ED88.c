/* func_L03_0032ED88: MATCH at level 03 and US; the level-07 place is a different function (offset 0x50 instead of 0x60, other callee): catalogue false fold, needs split_places before landing. */
/* (draft, checked) */
/* see log */
__asm__(".extern D_L03_001DF99C, 16");
extern char *D_L03_001DF99C;
extern void func_L03_00399CE0(char *);

void func_L03_0032ED88(char *obj) {
    int *p = (int *)(*(char **)(obj + 0x68) + 0x60);
    int i;
    for (i = 7; i >= 0; i--) {
        func_L03_00399CE0(D_L03_001DF99C + (*p << 8));
        p++;
    }
}
