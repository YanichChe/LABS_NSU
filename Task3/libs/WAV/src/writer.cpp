#include "writer.h"

using namespace writer;

Writer::Writer(const std::string path)
{
    outputFile.open(path, std::ios_base::binary);
    outputFile.seekp(wav::TOTAL_HEADER_SIZE, std::fstream::cur);
}

void Writer::writeHeader()
{
    outputFile.seekp(0, std::ios::beg);

    wav::Header RIFFHeader{wav::RIFF_CHUNK_ID, (uint32_t)outputFile.tellp() - wav::BYTE_SIZE};
    wav::Header FMTHeader{wav::FMT_CHUNK_ID, wav::FMT_CHUNK_SIZE};
    wav::Header dataHeader{wav::DATA_CHUNK_ID, (uint32_t)outputFile.tellp() - wav::TOTAL_HEADER_SIZE};

    wav.RIFFHeader = RIFFHeader;
    wav.WAVEFormat = wav::WAVE_FORMAT;
    wav.FMTHeader = FMTHeader;
    wav.audioFormat = wav::AUDIO_FORMAT;
    wav.numberChannels = wav::NUMBER_CHANNELS;
    wav.samplesPerSec = wav::SAMPLES_PER_SEC;
    wav.bytesPerSec = wav::BYTES_PER_SEC;
    wav.blockAlign = wav::BLOCK_ALIGN;
    wav.bitsPerSample = wav::BITS_PER_SAMPLE;
    wav.dataHeader = dataHeader;

    outputFile.write((const char *)&wav, sizeof(wav::WAV));

}

void Writer::writeSample(const wav::SampleBuffer *buffer)
{
    outputFile.write((const char*)buffer, sizeof(wav::SampleBuffer));
}