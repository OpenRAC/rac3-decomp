#include "common.h"

typedef struct {
    s32 identifier;
    u8 reserved4[0x2D];
    u8 active;
    u8 reserved32[6];
    void *head;
} State_L40_0053CE30;

typedef struct {
    u8 reserved[0x90];
    State_L40_0053CE30 *state;
} Actor_L40_0053CE30;

typedef struct {
    s32 result;
} Output_L40_0053CE30;

extern u8 D_001A5F70[0x10];
extern s32 func_L40_0053C768(Actor_L40_0053CE30 *);
extern Output_L40_0053CE30 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, s32, s32, s32, Output_L40_0053CE30 *);
extern void *func_L39_00669AC0(void *, void **);
extern void func_L40_0053B368(s32);
/* This eight-byte callee has several catalogue names across level copies. */
extern void func_L40_0053CBE0(void);

/* localdecomp:start func_L40_0053CE30 */
void func_L40_0053CE30(Actor_L40_0053CE30 *actor) {
    State_L40_0053CE30 *state = actor->state;
    s32 identifier = state->identifier;
    if (func_L40_0053C768(actor) != 0) {
        Output_L40_0053CE30 *output = func_L39_006699B0();
        if (output == 0) {
            return;
        }
        output->result = func_L39_00669978(2, identifier,
                                            *(s32 *)(D_001A5F70 + 8),
                                            identifier, output);
    }
    if (state != 0) {
        void *current = state->head;
        while (current != 0) {
            current = func_L39_00669AC0(current, &state->head);
        }
        state->active = 0;
    }
    func_L40_0053B368(identifier);
    func_L40_0053CBE0();
}
/* localdecomp:end func_L40_0053CE30 */
