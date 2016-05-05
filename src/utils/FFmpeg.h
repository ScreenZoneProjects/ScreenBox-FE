#ifndef FFMPEG_H
#define FFMPEG_H

#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS
#endif

namespace FFmpeg {
extern "C" {

#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#if AV_VERSION_INT(52, 2, 0) <= AV_VERSION_INT(LIBAVUTIL_VERSION_MAJOR, \
    LIBAVUTIL_VERSION_MINOR, LIBAVUTIL_VERSION_MICRO)
    #include <libavutil/channel_layout.h>
#endif
#include <libavresample/avresample.h>
#include <libavutil/opt.h>


/*

    const char * testFile = "Intro.flv";
    // Mettre en mémoire tous les codecs
    FFmpeg::av_register_all();
    // Création d'un contexte pour un playback
    FFmpeg::AVFormatContext *pFormatCtx = NULL;
    // Vérification si le contexte est valide pour une source spécifique
    if(FFmpeg::avformat_open_input(&pFormatCtx, testFile, NULL, 0, NULL) != 0)
        return -1;
    // Vérification des flux de données de la source
    if(FFmpeg::avformat_find_stream_info(pFormatCtx, NULL) < 0)
        return -1;
    // Debug manuel pour voir le contenu du flux
    FFmpeg::av_dump_format(pFormatCtx, 0, testFile, 0);
    // Exploration du flux jusqu'à la découverte du contexte du codec
    int i;
    int videoStreamIndex = -1;
    FFmpeg::AVCodecContext *pCodecCtxOrig = NULL;
    FFmpeg::AVCodecContext *pCodecCtx = NULL;
    for (i = 0; i< pFormatCtx->nb_streams; i++) {
        if (pFormatCtx->streams[i]->codec->codec_type == FFmpeg::AVMEDIA_TYPE_VIDEO) {
            videoStreamIndex = i;
            break;
        }
    }
    if (videoStreamIndex == -1) {
        return -1;
    }
    pCodecCtx = pFormatCtx->streams[videoStreamIndex]->codec;
    // Tentative pour trouver un decodeur adéquat à notre codec
    FFmpeg::AVCodec *pCodec = NULL;
    pCodec=FFmpeg::avcodec_find_decoder(pCodecCtx->codec_id);
    if (pCodec == NULL)
        return -1;
    // Copie du contexte pour eviter de travailler sur la source
    pCodecCtx = FFmpeg::avcodec_alloc_context3(pCodec);
    if(FFmpeg::avcodec_copy_context(pCodecCtx, pCodecCtxOrig) != 0) {
        return -1;
    }
    if(FFmpeg::avcodec_open2(pCodecCtx, pCodec) < 0)
        return -1;
    FFmpeg::AVFrame *pFrame = NULL;
    pFrame=FFmpeg::av_frame_alloc();
    // Allocate an AVFrame structure
    pFrameRGB=FFmpeg::av_frame_alloc();
    if(pFrameRGB==NULL)
      return -1;
    //
    uint8_t *buffer = NULL;
    int numBytes;
    numBytes=FFmpeg::avpicture_get_size(FFmpeg::PIX_FMT_RGB24, pCodecCtx->width, pCodecCtx->height);
    buffer=(uint8_t *)FFmpeg::av_malloc(numBytes*sizeof(uint8_t));
    FFmpeg::avpicture_fill((AVPicture *)pFrameRGB, buffer, FFmpeg::PIX_FMT_RGB24, pCodecCtx->width, pCodecCtx->height);

*/
}
}

#endif // FFMPEG_H
