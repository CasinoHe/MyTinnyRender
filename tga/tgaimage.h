#pragma once

#include <cstdint>

// https://github.com/ssloy/tinyrenderer.git
namespace my_tinny_render
{
  // from: http://www.paulbourke.net/dataformats/tga/
  struct STGAHeader
  {
    int8_t idlength;
    int8_t colourmaptype;
    int8_t datatypecode;
    int16_t colourmaporigin;
    int16_t colourmaplength;
    int8_t colourmapdepth;
    int16_t x_origin;
    int16_t y_origin;
    int16_t width;
    int16_t height;
    int8_t bitsperpixel;
    int8_t imagedescriptor;
  };

  class STGAColor
  {
  public:
    union
    {
      struct
      {
        uint8_t m_b, m_g, m_r, m_a;
      };

      uint8_t m_raw[4];
      uint32_t m_val;
    };
    int m_bytespp;

    STGAColor() : m_val(0), m_bytespp(1) {}
    STGAColor(uint8_t R, uint8_t G, uint8_t B, uint8_t A) : m_b(B), m_g(G), m_r(R), m_a(A), m_bytespp(4) {}
    STGAColor(int v, int bpp) : m_val(v), m_bytespp(bpp) {}

    STGAColor(STGAColor &color) : m_val(color.m_val), m_bytespp(color.m_bytespp) {}
    STGAColor(const uint8_t *p, int app)
    {
      for (int index = 0; index < app; index++)
      {
        m_raw[index] = p[index];
      }
    }
    STGAColor &operator=(STGAColor &color)
    {
      m_val = color.m_val;
      m_bytespp = color.m_bytespp;
      return *this;
    }
  };

  class CTGAImage
  {
  };
} // namespace my_tinny_render