#ifndef LAB1_WAV_H
#define LAB1_WAV_H
#include <string>
#include <cstdint>
#include <array>

// CORRECT INPUT ---------------------------------------------------------------
const uint32_t RIFF_CHUNK_ID = 0x46464952;
const uint32_t WAVE_FORMAT = 0x45564157;

const uint32_t FMT_CHUNK_ID = 0x20746d66;
const uint16_t AUDIO_FORMAT = 0x0001;
const uint16_t NUMBER_CHANNELS = 1;
const uint32_t SAMPLES_PER_SEC = 44100;

const uint16_t BYTE_SIZE = 8;
const uint16_t BITS_PER_SAMPLE = BYTE_SIZE * sizeof(int16_t);
const uint16_t BLOCK_ALIGN = BITS_PER_SAMPLE * NUMBER_CHANNELS / BYTE_SIZE;
const uint32_t BYTES_PER_SEC = BLOCK_ALIGN * SAMPLES_PER_SEC;

const uint32_t DATA_CHUNK_ID = 1414744396; //??????????????????
//-----------------------------------------------------------------------------

struct WAV
{
    /* RIFF Chunk  */
    uint32_t RIFFChunkId;
    uint32_t RIFFChunkSize;
    uint32_t WAVEFormat;

    /* fmt sub-chunk */
    uint32_t FMTChunkId;
    uint32_t FMTChunk1Size;
    uint16_t audioFormat;
    uint16_t numberChannels;
    uint32_t samplesPerSec;
    uint32_t bytesPerSec;
    uint16_t blockAlign;
    uint16_t bitsPerSample;

    /* data sub-chunk */
    uint32_t dataChunkId;
    uint32_t dataChunkSize;
};

#endif // LAB1_WAV_H
