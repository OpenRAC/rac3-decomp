/* near miss (level 7, Annihilation Nation): 10 differences. The loop body and epilogue are
   byte-identical; only the preheader order of the loop-invariant address materialisations
   differs. Retail: 1427F0, 2B0EB0, 1425C0, 2C72C0, move a0, 0xF0, 1E0CD0, 0xF; ours:
   1427F0, 1425C0, 2B0EB0, 2C72C0, 1E0CD0, 0xF0, move a0, with the same registers and
   instructions. About 19 wordings (ascending/descending/do-while/!=/u32 counters, pointer
   walk, explicit table and destination pointers, body orderings) stayed at 10 or worse.
   The 0x8A read must go through a typed entry pointer; indexing the array inline folds the
   offset into the symbol's %lo. Same failure class as func_L07_003328D0. */
typedef struct {
    s32 f0;
    s32 f4;
} E_332848;

typedef struct {
    u8 pad0[0x8A];
    u16 f8A;
    u8 pad8C[0xF0 - 0x8C];
} T_332848;

typedef struct {
    u8 pad0[0xBF];
    u8 fBF;
} B_332848;

typedef struct {
    u8 pad0[0x68];
    B_332848 *p68;
} O_332848;

extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern E_332848 D_L07_002B0EB0[];
extern T_332848 D_L07_002C72C0[];
extern s32 D_L07_001E0CD0[];

void func_L07_00332848(u8 *a0) {
    s32 i;

    for (i = 0; i < 16; i++) {
        s32 idx = D_L07_002B0EB0[i].f0;
        s32 v = D_001427F0[idx];
        u8 t = D_001425C0[idx];
        T_332848 *e = &D_L07_002C72C0[t];

        D_L07_001E0CD0[i] = v;
        D_001427F0[idx] = e->f8A;
    }
    ((O_332848 *)a0)->p68->fBF = 1;
}
