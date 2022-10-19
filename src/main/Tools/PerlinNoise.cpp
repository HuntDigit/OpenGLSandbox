#include<iostream>

#include "PerlinNoise.h"

PerlinNoise::PerlinNoise(unsigned int size, unsigned int seed) 
	: m_Size(size), m_Seed(seed), m_Octaves(1.0f), m_Bias(2.0f)
{

}

PerlinNoise::~PerlinNoise()
{
}

const std::vector<float>& PerlinNoise::getPerlinNoise1D() const
{
	return m_PerlinNoise1D;
}

const std::vector<float>& PerlinNoise::getPerlinNoise2D() const
{
	return m_PerlinNoise2D;
}

void PerlinNoise::generateNoise1D()
{
	m_Noise1D.resize(m_Size);

	for (int i = 0; i < m_Size; i++)
		m_Noise1D[i] = ((float)rand()) / ((float)RAND_MAX);
}

void PerlinNoise::generateNoise2D()
{
	m_Noise2D.resize(m_Size * m_Size);

	for (int i = 0; i < m_Size * m_Size; i++)
		m_Noise2D[i] = ((float)rand()) / ((float)RAND_MAX);
}

void PerlinNoise::generatePerlinNoise1D(int nOctaves, float fBias)
{
	m_PerlinNoise1D.resize(m_Size);

	if (fBias < 0.2f) fBias = 0.2f;

	for (int x = 0; x < m_Size; x++)
	{
		float fNoise = 0.0f;
		float fScale = 1.0f;
		float fScaleAcc = 0.0f;

		for (int y = 0; y < nOctaves; y++)
		{
			int nPitch = m_Size >> y;
			if (nPitch < 1) nPitch = 1;
			int nSample1 = (x / nPitch) * nPitch;
			int nSample2 = (nSample1 + nPitch) % m_Size;

			float fBlend = (float)(x - nSample1) / (float)nPitch;
			float fSample = (1.0f - fBlend) * m_Noise1D[nSample1] + fBlend * m_Noise1D[nSample2];
			fNoise += fSample * fScale;
			fScaleAcc += fScale;
			fScale = fScale / fBias;
		}

		m_PerlinNoise1D[x] = fNoise;
	}
}

void PerlinNoise::generatePerlinNoise2D(int nOctaves, float fBias)
{
	m_PerlinNoise2D.resize(m_Size * m_Size);

	if (fBias < 0.2f) fBias = 0.2f;

	for (int x = 0; x < m_Size; x++)
	{
		for (int y = 0; y < m_Size; y++)
		{
			float fNoise = 0.0f;
			float fScale = 1.0f;
			float fScaleAcc = 0.0f;

			for (int o = 0; o < nOctaves; o++)
			{
				int nPitch = m_Size >> o;
				if (nPitch < 1) nPitch = 1;

				int nSampleX1 = (x / nPitch) * nPitch;
				int nSampleY1 = (y / nPitch) * nPitch;

				int nSampleX2 = (nSampleX1 + nPitch) % m_Size;
				int nSampleY2 = (nSampleY1 + nPitch) % m_Size;

				float fBlendX = (float)(x - nSampleX1) / (float)nPitch;
				float fBlendY = (float)(y - nSampleY1) / (float)nPitch;

				float fSampleT = (1.0f - fBlendX) * m_Noise2D[nSampleY1 * m_Size + nSampleX1] + fBlendX * m_Noise2D[nSampleY1 * m_Size + nSampleX2];
				float fSampleB = (1.0f - fBlendX) * m_Noise2D[nSampleY2 * m_Size + nSampleX1] + fBlendX * m_Noise2D[nSampleY2 * m_Size + nSampleX2];

				fNoise += (fBlendY * ( fSampleB - fSampleT ) + fSampleT) * fScale;
				fScaleAcc += fScale;
				fScale = fScale / fBias;
			}

			m_PerlinNoise2D[y * m_Size + x] = fNoise / fScaleAcc;
		}
	}
}

std::vector<unsigned char> PerlinNoise::getSample2D()
{
	m_Sample2D.resize(m_Size * m_Size);
	for (int i = 0; i < m_Size * m_Size; i++)
	{
		m_Sample2D[i] = (unsigned int)(m_PerlinNoise2D[i] * 255.f);
	}

	return m_Sample2D;
}

unsigned char* PerlinNoise::getCSample2D()
{
	unsigned char* sample = new unsigned char[m_Size * m_Size];
	for (int i = 0; i < m_Size * m_Size; i++)
	{
		sample[i] = (unsigned int)(m_PerlinNoise2D[i] * 255.f);
	}

	return sample;
}