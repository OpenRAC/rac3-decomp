/* Near miss, ported from rac4-decomp's func_L00_005382C8 (cross-game near pair). NEAR: 16-byte save-slot frame (0x50, sd at 0x10/0x20/0x30/0x40) plus lui $v0 reuse for D_L39_0046EA50; structure otherwise identical */
__asm__(".extern D_L39_0046EA50, 16");
typedef struct {
    void *data;
    s32 count;
    s32 capacity;
    s32 unkC;
    u32 flags;
} Vec_004FC4B8;

extern s32 D_L39_0046EA50;
extern char D_L39_00478F08[];
extern void *func_0011D380(void *, const void *, unsigned int);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern s32 func_L39_00505980(u32, s32, s32, s32);

Vec_004FC4B8 *func_L39_004FC4B8(Vec_004FC4B8 *vec, s32 newCap) {
    char buf[16];
    void *mem;

    buf[0] = 0;
    func_L39_00505980((u32)buf, (s32)D_L39_00478F08, 340, ++D_L39_0046EA50);
    if (vec->capacity < newCap) {
        if (vec->flags & 2) {
            return 0;
        }
        mem = func_L39_004BEED8((newCap + 1) * 8);
        if (mem == 0) {
            return 0;
        }
        if (vec->data != 0) {
            func_0011D380(mem, vec->data, vec->count * 8);
            func_L39_004BEF28(vec->data);
        }
        vec->data = mem;
        vec->capacity = newCap;
    }
    return vec;
}
