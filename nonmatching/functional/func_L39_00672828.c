/* functional: high. Compiles; retail's integer abs is the blezl+neg asm pair, here plain abs; bytes differ only in scheduling. */
typedef struct Ent_00672828 {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x80 - 6];
} Ent_00672828;
extern Ent_00672828 D_L39_0049C890_00672828[];

void func_L39_00672828(s32 i, s16 *p, s16 x) {
    s32 cur = *p;
    s32 d;
    x = x - D_L39_0049C890_00672828[i].h4;
    d = cur - x;
    if (d < 0) d = -d;
    if (x > 0 && (x < cur || d < cur / 2)) *p = x;
}
