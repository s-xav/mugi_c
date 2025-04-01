#ifndef MUGI_H
#define MUGI_H

#include <stdint.h>

typedef struct {
    uint64_t a[3];
    uint64_t b[16];
} MUGI_State_t;

/**
 * Init MUGI state
 * @param State MUGI State
 * @param Key Key to init with
 * @param IV IV to init with
 * @return 0 on success
 */
int MUGI_Init(MUGI_State_t *State, const unsigned char Key[16], const unsigned char IV[16]);

/**
 * Performs an update on the state to generate new data
 * @param State MUGI State
 * @return 0 on success
 */
int MUGI_Update(MUGI_State_t *State);

/**
 * Generate the next 64bit stream unit and updates the state internally.
 * @param State MUGI State
 * @param Output Key-stream unit
 * @return 0 on success
 */
int MUGI_Stream_Unit(MUGI_State_t *State, uint64_t *Output);

/**
 * Encrypt or decrypt data from a given state
 * @param State MUGI State
 * @param Input Input data
 * @param Output Output data
 * @param Length Data length to process
 * @return 0 on success
 */
int MUGI_Process_Bytes(
    MUGI_State_t *State,
    const unsigned char *Input,
    unsigned char *Output,
    size_t Length
);

/**
 * Generate bytes from MUGI to a given buffer of given length. (PRNG Usage)
 * @param State State
 * @param Output Output buffer
 * @param Length Length of the buffer
 * @return 0 on success
 */
int MUGI_Generate_Bytes(MUGI_State_t *State, unsigned char *Output, size_t Length);

#endif //MUGI_H
