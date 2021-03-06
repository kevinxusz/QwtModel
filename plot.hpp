#ifndef PLOT_HPP
#define PLOT_HPP

#include <qwt_plot.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_curve.h>
#include <qwt_picker_machine.h>
#include <qwt_scale_engine.h>
#include <qwt_scale_draw.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_marker.h>
#include <qwt_symbol.h>
#include <qwt_wheel.h>

constexpr double INCR = 0.0075;
constexpr double SHIFT = INCR * 2060;

class Plot : public QwtPlot
{
    Q_OBJECT

public:
    Plot(QWidget *parent, const QString objectName);

    /* Hints for resize QwtPlot */
    QSize sizeHint() const { return QSize(700, 200); }
    QSize minimumSizeHint() const { return QSize(700, 200); }
    /* Setters */
    void setMarker(int number);
    void setPickers(bool enable);
    void setThresholdPickers(bool enable);
    void setZoomer(bool enable);
    void setCentralFrequency(double cntrFrequency);
    void setMaxHold(bool holdOn);
    void setExpCoefficient(double expCoeff);
    /* Getters */
    QwtPlotPicker* getMarkerPicker(bool prime);
    QwtPlotPicker* getThreshPicker(bool prime);
    QwtPlotZoomer* getZoomer();
    QVector<int> getMarkerBounds();
    QVector<int> getThresholdBounds();
    /* Others */
    void resetMarkers();
    void moveMarker(double position, bool prime);
    void moveThreshold(double position, bool prime);

public slots:
    void updateCurve(const QVector<double> &samplesPh);
    void updateCurve(const QVector<double> &samplesAm1, const QVector<double> &samplesAm2);
    void equalZoom(const QRectF &rect);

private:
    QwtPlotCurve *curve1;
    QwtPlotCurve *curve2;
    QwtPlotCurve *curveMax;
    QwtPlotPicker *pickerMarkPr;
    QwtPlotPicker *pickerMarkSec;
    QwtPlotPicker *pickerThrPr;
    QwtPlotPicker *pickerThrSec;
    QwtPlotMarker *markerPr;
    QwtPlotMarker *markerSec;
    QwtPlotMarker *thresholdPr;
    QwtPlotMarker *thresholdSec;
    QwtPlotZoomer   *zoomer;

    QVector<QwtPlotMarker*> markerVector;
    QVector<QColor> colors;
    QVector<double> maxSamples;

    int markPairNmr;
    double expCoeff;
    double cntrFrequency;
};

#endif // PLOT_HPP
