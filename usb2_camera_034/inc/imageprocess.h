#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <QtCore>
//#include "qimage.h"
#include "qpixmap.h"
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

class ImageProcess : public QObject
{
	Q_OBJECT

public:
	ImageProcess();
	~ImageProcess();
	void initialize(int width, int height, bool isColor);

	void setWidth(int width);
	void setHeight(int height);
	void imageToPixmap(QImage &image);
	void saveOriginalData(unsigned short *data);
	void enableSaveData();
	void setImageColorOrBlack(bool isColor);
	
	void disableImageProcess();
	void enableImageProcess();

	void setPauseFlag(bool flag);

	void autoWhiteBalance(cv::Mat &src, cv::Mat &dst);

	void dataToImage(unsigned char *data, int bitsPerPixel, int width, int height, unsigned short wavelen);

	void setSavingPath(QString path);
	QString getSavingPath();
	void takeOriginalImage(const cv::Mat& image,  const QPixmap& pixmap, unsigned short wavelen);
	void takeSpectrumImage(const cv::Mat& image, const QPixmap& pixmap, unsigned short wavelen);
	void takeShowingImage(const QPixmap& pixmap);
	void setTakingImageFlag(bool flag);
	void setCapturingSpectrumFlag(bool flag);
	void setCapturingReferenceFlag(bool flag);

	void setHorizontal();
	void setVertical();

	void setLowIlluminationChecked(bool checked);
	
signals:
	void showImage(QPixmap image);
	void referenceWavelengthInfo(unsigned short wavelen, int addOrSub);

public slots:
	void dataToImage();

private:
	unsigned char *m_imageData;
	
	int m_imageHeight;
	int m_imageWidth;

	QPixmap m_imageShow;
	QImage m_image;
	QString m_path;

	bool m_saveOriginalDataFlag;
	bool m_isColor;

	bool m_imageProcessingFlag;
	bool m_pauseFlag;
	bool m_isTakingImage;
	bool m_isCapturingSpectrum;
	bool m_isCapturingReference;

	bool m_horizontalMirror;
	bool m_verticalMirror;

	bool m_lowIlluminationChecked;
};

inline void ImageProcess::setWidth(int width)
{
	m_imageWidth = width;
}

inline void ImageProcess::setHeight(int height)
{
	m_imageHeight = height;
}


#endif