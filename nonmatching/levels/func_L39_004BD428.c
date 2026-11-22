// near miss: ~44 words differ; retail: beql key==0 into a shared zero-fill tail, count cached in t4, key loop indexed (t3+i*8) with first iteration peeled, fail block after the success jr. Semantics are as below.
typedef struct { u32 key; s32 off; } E_004BD428;
typedef struct { s32 n; E_004BD428 e[1]; } T_004BD428;
extern T_004BD428 D_L39_004BE388;
void func_L39_004BD428(u32 key, s32 *o1, s32 *o2, s32 **o3) {
    T_004BD428 *t = &D_L39_004BE388;
    s32 off = -1;
    s32 i;
    s32 *p;
    if (key != 0) {
    for (i = 0; i < t->n; i++) {
        if (t->e[i].key >> 1 == key) {
            off = t->e[i].off;
            break;
        }
    }
    if (off >= 0) {
    p = (s32 *)((u8 *)&t->e[t->n] + off);
    *o1 = p[0];
    *o2 = p[1];
    *o3 = p + 2;
    return;
    }}
    *o1 = 0;
    *o2 = 0;
    *o3 = 0;
}
