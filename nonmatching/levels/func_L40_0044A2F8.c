/* func_L40_0044A2F8: 75 diff with the file's flags. Frame, the 64-bit product (long), the 16-entry search loop and the final stores are in; the locals are a struct at sp (v at 0, k at 4, z at 8) written through pointers. Differs: register allocation and order of the odd/even paths (retail computes the odd path first with the same loads), the dead z store, and the loop-carried sums. Tried: plain locals (no frame), separate address-taken locals (76/74), the struct (75). */
__asm__(".extern D_001D6D30_sda, 4");
__asm__(".extern D_001D6D38_sda, 8");
__asm__(".extern D_001D6D2C_sda, 4");
__asm__(".extern D_001D6D28_sda, 4");
extern s32 D_001D6D30_sda;
extern s32 D_001D6D38_sda[2];
extern s32 D_001D6D2C_sda;
extern s32 D_001D6D28_sda;
extern u8 D_L40_00257F40[];

typedef struct {
    s16 v;
    s32 k;
    s32 z;
} Loc044;

s32 func_L40_0044A2F8(s32 a0, s32 *a1, s16 *a2)
{
    Loc044 L;
    s32 r;
    s32 i;
    u8 *p;
    s32 c;
    s32 *pk;
    s32 *pz;

    pk = &L.k;
    pz = &L.z;
    if (a0 & 1) {
        L.v = (s16)((a0 >> 23) << 2);
        L.k = (a0 >> 1) & 0x3FFFFF;
    } else {
        *pz = 0;
        r = (s32)(((long)D_001D6D30_sda * (long)(a0 >> 12)) >> 20);
        r = r + D_001D6D38_sda[0];
        if (r >= D_001D6D38_sda[1]) {
            do {
                r = r + (D_001D6D38_sda[0] - D_001D6D38_sda[1]);
            } while (r >= D_001D6D38_sda[1]);
            *pz = 0;
        }
        *pk = r;
    }
    c = (D_001D6D2C_sda + 1) & 0xF;
    if (c == D_001D6D28_sda) {
        return 0;
    }
    p = D_L40_00257F40;
    for (i = 0; i < 16; i++) {
        if (*(s32 *)p == L.k && *(s16 *)(p + 4) == L.v) {
            return 0;
        }
        p += 16;
    }
    *a1 = L.k;
    *a2 = L.v;
    return 1;
}
