/* func_L01_0049D190: MATCH (0 diff) with @ps2as (check.py --as ps2as, S or N); 26 diff with the file's flags
   (L01_0049CF68.c has none). 4 of the file's 9 other C blocks stop matching under @ps2as, so it needs a file cut at 0x49D190
   with its own @ps2as line. D_001D52FC_0049D190 is the pointer view of the front end's singleton (the $gp view D_001D52FC
   is what other files use). */
typedef struct { u8 pad0[0x1C4]; u32 w1C4; } S_0049D190;
extern S_0049D190 *D_001D52FC_0049D190;
extern void func_L01_0049CFA8(void);
extern s32 func_L01_0049B550(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(void *);

void func_L01_0049D190(void *a) {
    if (D_001D52FC_0049D190->w1C4 & 0x40) {
        func_L01_0049CFA8();
    }
    if (D_001D52FC_0049D190->w1C4 & 0x910) {
        func_L01_00517748(func_L01_0049B550());
        func_L01_00516090(a);
    }
}
