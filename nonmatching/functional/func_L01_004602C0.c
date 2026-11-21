/* functional: medium. 223 diff at default flags (structure/regalloc; the repo draft re-read against PAL asm: callee names fixed to func_00381FF0, jump-table case 3 -> default inferred from block layout since jtbl data not available; scratchpad 0x70000000 text buffer kept as fixed hardware address) */
/* localdecomp:start func_L01_004602C0 */
typedef struct {
    s32 text;
    u16 action;
    s16 next;
    s16 kind;
    s16 test;
    s16 yes;
    s16 no;
    u16 flags;
    u8 pad12[10];
} Node_004602C0;
typedef struct {
    u8 pad0[4];
    u16 previous;
    u8 pad6[2];
    u8 flag;
    u8 pad9[0x36 - 9];
    s16 current;
    s32 time;
    Node_004602C0 *nodes;
} State_004602C0;
typedef struct { char *v[6]; } Words_004602C0;
typedef struct {
    u8 pad0[0x7C];
    s32 value;
    u8 pad80[0x10];
    u16 cost;
    u8 pad92[0xF0 - 0x92];
} Row_004602C0;

extern s32 D_L01_001DFB40;
extern void *D_L01_001DFC18[];
extern void *D_L01_001DFC1C[];
extern s32 D_L01_001DFC24[];
extern Words_004602C0 D_L01_001D7E38;
extern char D_L01_001D7E60[];
extern char D_L01_001D7E70[];
extern u8 D_001425C0[];
extern u8 D_00142CA0[];
extern u8 D_00142D40[];
extern s32 D_00142660[];
extern s16 D_001426A2[];
extern u8 D_00143A07[];
extern Row_004602C0 D_L01_002C5600[];
extern s32 func_L01_004526F8(void);

static __inline__ s32 condition_004602C0(Node_004602C0 *node) {
    extern s32 func_L01_004526F8(void);
    s32 result;
    switch ((s16)(node->kind - 1)) {
        case 0: return D_L01_002C5600[D_001425C0[node->test]].value<=D_00142660[0];
        case 1: return D_00142CA0[node->test]!=0;
        case 2: { s32 ready=0; if (D_00142CA0[node->test]) ready=!D_00142D40[node->test]; return ready; }
        case 4: return func_L01_004526F8()>=node->test;
        case 5:
            result=0;
            if (D_00142660[0]>=D_L01_002C5600[D_001425C0[node->test]].cost) result=func_L01_004526F8()>=4;
            return result;
        case 6: return D_001426A2[0]>=node->test;
        default: return 0;
    }
}
void func_L01_004602C0(void *obj, State_004602C0 *state, s32 advance) {
    extern void func_0045A590(s32, s32, s32, s32, s32);
    extern char *func_00381FF0(s32);
    extern void func_0011B754(char *, char *);
    extern char *func_0011BD18(char *, char *);
    extern s32 func_0011B2E8(char *, char *, ...);
    extern void func_0041D0F8(char *);
    char text[256];
    Words_004602C0 words;
    char number[32];
    Node_004602C0 *node = &state->nodes[state->current];
    Node_004602C0 *n;
    s32 result;
    s16 next;
    u16 flags;

    if (state->nodes == 0) return;
    if (advance) {
        state->previous = state->current;
        state->time = D_L01_001DFB40;
        if (state->current != node->next) {
            n = &state->nodes[node->next];
            flags = node->flags;
            state->current = node->next;
            node = n;
            state->flag = node->flags & 1;
            if (flags & 4) {
                do {
                    D_L01_001DFC18[0] = obj;
                    D_L01_001DFC1C[0] = state;
                } while (0);
                if (node->action & 0x4000)
                    func_0045A590(1, 1, 0, (s16)(node->action ^ 0x4000), 0);
                else
                    func_0045A590(2, 1, (s16)node->action, 0, 0);
            }
        }
    }
    if (state->current == -1) return;
    D_L01_001DFC24[0] = node->text;
    if (node->kind == 6) {
        char *p;
        s32 cost;

        words = D_L01_001D7E38;
        func_0011B754((char *)0x70000000, func_00381FF0(node->text));
        p = func_0011BD18((char *)0x70000000, D_L01_001D7E70);
        if (p) p[1] = 's';
        cost = D_L01_002C5600[D_001425C0[node->test]].cost;
        func_0011B2E8(number, D_L01_001D7E60, cost / 1000, words.v[D_00143A07[0] % 6], cost % 1000);
        func_0011B2E8(text, (char *)0x70000000, number);
    } else {
        func_0011B2E8(text, func_00381FF0(node->text));
    }
    if (D_L01_001DFC24[0]) func_0041D0F8(text);
    if (node->kind == 0) return;
    result = condition_004602C0(node);
    if (result) next = node->yes;
    else next = node->no;
    if (next != state->current) {
        state->current = next;
        state->time = D_L01_001DFB40;
        node = &state->nodes[next];
        state->flag = node->flags & 1;
        func_L01_004602C0(obj, state, 0);
    }
}
/* localdecomp:end func_L01_004602C0 */
