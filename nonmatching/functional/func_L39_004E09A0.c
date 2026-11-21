/* exact: byte-identical at level 39 (refcount release then free). */
typedef struct S2_004E09A0 { u8 pad[8]; s32 count; } S2_004E09A0;
typedef struct S_004E09A0 { s32 f0; S2_004E09A0 *p; } S_004E09A0;
extern void func_L39_004F9A88(void *);
extern void func_L39_004BEF28(void *);

void func_L39_004E09A0(S_004E09A0 *a) {
    if (--a->p->count == 0) {
        func_L39_004F9A88(a->p);
    }
    func_L39_004BEF28(a);
}
