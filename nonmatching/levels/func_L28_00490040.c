/* Ported from rac2-decomp's func_L00_0037DE30 (a twin of this function's code), names renamed from retail's
   relocations; 2 instruction(s) still differ under this file's flags. */
extern int func_L01_004C82C0(char *key, char *owner);

char *func_L28_00490040(char *key, char **list, int count, int kind)
{
    char *found = 0;
    int best = 0x270F;
    int i;
    for (i = 0; i < count; i++) {
        int v;
        if (kind <= 0 || *(short *)(*(char **)(list[i] + 0x24) + 0x46) == kind) {
            v = func_L01_004C82C0(key, list[i]);
            if (v < best && v != -1) {
                found = list[i];
                best = v;
            }
        }
    }
    return found;
}