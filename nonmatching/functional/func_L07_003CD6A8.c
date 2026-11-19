/* functional: high. none */
typedef struct {
    f32 f0;
    s32 f4;
} S_003CD938;

extern S_003CD938 D_L07_001DE6F4[] __attribute__((section(".sdata")));
void func_L07_003CD610(void *);
f32 func_L07_003CE2F8(void *);
s32 func_L07_003CE858(void *);
s32 func_L07_003CEA38(void *);
void func_L07_003CD2E8(void *, s32);

void func_L07_003CD6A8(void *arg0, f32 f1) {
    void *s = *(void **)((u8 *)arg0 + 0x68);
    u8 i;
    f32 v;

    func_L07_003CD610(arg0);
    v = func_L07_003CE2F8(arg0);
    i = *(u8 *)((u8 *)s + 0x404);
    if (0.0f < f1) {
        if (v < D_L07_001DE6F4[i].f0) {
            if (*(s32 *)((u8 *)s + 0x418) == -1) {
                *(s32 *)((u8 *)s + 0x418) = func_L07_003CE858(arg0);
            }
            if (func_L07_003CEA38(arg0)) {
                func_L07_003CD2E8(arg0, *(u8 *)((u8 *)s + 0x404) + 0xC);
            }
        } else if (f1 + D_L07_001DE6F4[i].f0 < v) {
            func_L07_003CD2E8(arg0, 9);
        }
    } else {
        if (v < D_L07_001DE6F4[i].f0) {
            if (*(s32 *)((u8 *)s + 0x418) == -1) {
                *(s32 *)((u8 *)s + 0x418) = func_L07_003CE858(arg0);
            }
            if (func_L07_003CEA38(arg0)) {
                func_L07_003CD2E8(arg0, 0xB);
            }
        }
    }
}
