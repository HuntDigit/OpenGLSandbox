#pragma once
#include<vector>

class PerlinNoise
{
private:
	unsigned int m_Size;
	unsigned int m_Seed;
	unsigned int m_Octaves;

	float m_Bias;

	std::vector<float> m_Noise1D;
	std::vector<float> m_Noise2D;

	std::vector<float> m_PerlinNoise1D;
	std::vector<float> m_PerlinNoise2D;

	std::vector<unsigned char> m_Sample2D;


public:
	PerlinNoise(unsigned int size, unsigned int seed);
	~PerlinNoise();

	const std::vector<float>& getPerlinNoise1D() const;
	const std::vector<float>& getPerlinNoise2D() const;

	std::vector<unsigned char> getSample2D();
	unsigned char* getCSample2D();

	void generateNoise1D();
	void generateNoise2D();
	void generatePerlinNoise1D(int nOctaves, float fBias);
	void generatePerlinNoise2D(int nOctaves, float fBias);
};

