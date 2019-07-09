//
// Created by xixiliadorabarry on 1/24/19.
//
#ifndef PARAM_STRUCT_DEFINE_H
#define PARAM_STRUCT_DEFINE_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

using std::vector;



//----------------------------------------------------------------------------------------------------------------------
// 此结构体为能量机关模块的结构体，用于寻找矩形轮廓
// ---------------------------------------------------------------------------------------------------------------------
struct EnergyPart {
	cv::RotatedRect rect;
	float angle;
	vector<cv::Point> contour;

	explicit EnergyPart(vector<cv::Point> &c) : contour(c) {
		rect = cv::minAreaRect(c);
		angle = cv::minAreaRect(c).angle;
	};

	EnergyPart(cv::RotatedRect rect=cv::RotatedRect(), float angle=0, vector<cv::Point> contour=vector<cv::Point>()):rect(rect),angle(angle),contour(contour){};
};



//----------------------------------------------------------------------------------------------------------------------
// 此结构体包括能量机关参数
// ---------------------------------------------------------------------------------------------------------------------
struct EnergyPartParam {
	int GRAY_THRESH;//二值化阈值
	int SPLIT_GRAY_THRESH;//通道分离二值化阈值
	int FAN_GRAY_THRESH;//扇叶识别二值化阈值
	int ARMOR_GRAY_THRESH;//装甲板识别二值化阈值

	long FAN_CONTOUR_AREA_MAX;//扇叶面积最大值
	long FAN_CONTOUR_AREA_MIN;//扇叶面积最小值
	long FAN_CONTOUR_LENGTH_MIN;//扇叶长边长度最小值
    long FAN_CONTOUR_LENGTH_MAX;//扇叶长边长度最大值
	long FAN_CONTOUR_WIDTH_MIN;//扇叶宽边长度最小值
    long FAN_CONTOUR_WIDTH_MAX;//扇叶宽边长度最大值
	float FAN_CONTOUR_HW_RATIO_MAX;//扇叶长宽比最大值
	float FAN_CONTOUR_HW_RATIO_MIN;//扇叶长宽比最小值
    float FAN_CONTOUR_AREA_RATIO_MIN;//装甲板轮廓占旋转矩形面积比最小值

	long ARMOR_CONTOUR_AREA_MAX;//装甲板面积最大值
	long ARMOR_CONTOUR_AREA_MIN;//装甲板面积最小值
	long ARMOR_CONTOUR_LENGTH_MIN;//装甲板长边长度最小值
	long ARMOR_CONTOUR_WIDTH_MIN;//装甲板长边长度最大值
	long ARMOR_CONTOUR_LENGTH_MAX;//装甲板宽边长度最小值
	long ARMOR_CONTOUR_WIDTH_MAX;//装甲板宽边长度最大值
	float ARMOR_CONTOUR_HW_RATIO_MAX;//装甲板长宽比最大值
	float ARMOR_CONTOUR_HW_RATIO_MIN;//装甲板长宽比最小值
	float ARMOR_CONTOUR_AREA_RATIO_MIN;//装甲板轮廓占旋转矩形面积比最小值

    long CENTER_R_CONTOUR_AREA_MAX;//风车中心R面积最大值
    long CENTER_R_CONTOUR_AREA_MIN;//风车中心R面积最小值
    long CENTER_R_CONTOUR_LENGTH_MIN;//风车中心R长边长度最小值
    long CENTER_R_CONTOUR_WIDTH_MIN;//风车中心R长边长度最大值
    long CENTER_R_CONTOUR_LENGTH_MAX;//风车中心R宽边长度最小值
    long CENTER_R_CONTOUR_WIDTH_MAX;//风车中心R宽边长度最大值
    float CENTER_R_CONTOUR_HW_RATIO_MAX;//风车中心R长宽比最大值
    float CENTER_R_CONTOUR_HW_RATIO_MIN;//风车中心R长宽比最小值
    float CENTER_R_CONTOUR_AREA_RATIO_MIN;//装甲板轮廓占旋转矩形面积比最小值
    float CENTER_R_CONTOUR_INTERSETION_AREA_MIN;//中心R占ROI区的面积最小值

    long FLOW_STRIP_FAN_CONTOUR_AREA_MAX;//流动条扇叶（待击打）面积最大值
    long FLOW_STRIP_FAN_CONTOUR_AREA_MIN;//流动条扇叶（待击打）面积最小值
    long FLOW_STRIP_FAN_CONTOUR_LENGTH_MIN;//流动条扇叶（待击打）长边长度最小值
    long FLOW_STRIP_FAN_CONTOUR_WIDTH_MIN;//流动条扇叶（待击打）宽边长度最小值
    long FLOW_STRIP_FAN_CONTOUR_LENGTH_MAX;//流动条扇叶（待击打）长边长度最大值
    long FLOW_STRIP_FAN_CONTOUR_WIDTH_MAX;//流动条扇叶（待击打）宽边长度最大值
    float FLOW_STRIP_FAN_CONTOUR_HW_RATIO_MAX;//流动条扇叶（待击打）长宽比最大值
    float FLOW_STRIP_FAN_CONTOUR_HW_RATIO_MIN;//流动条扇叶（待击打）长宽比最小值
    float FLOW_STRIP_FAN_CONTOUR_AREA_RATIO_MAX;//装甲板轮廓占旋转矩形面积比最小值
    float FLOW_STRIP_FAN_CONTOUR_AREA_RATIO_MIN;//装甲板轮廓占旋转矩形面积比最小值

    long FLOW_STRIP_CONTOUR_AREA_MAX;//流动条（待击打）面积最大值
    long FLOW_STRIP_CONTOUR_AREA_MIN;//流动条（待击打）面积最小值
    long FLOW_STRIP_CONTOUR_LENGTH_MIN;//流动条（待击打）长边长度最小值
    long FLOW_STRIP_CONTOUR_WIDTH_MIN;//流动条（待击打）宽边长度最小值
    long FLOW_STRIP_CONTOUR_LENGTH_MAX;//流动条（待击打）长边长度最大值
    long FLOW_STRIP_CONTOUR_WIDTH_MAX;//流动条（待击打）宽边长度最大值
    float FLOW_STRIP_CONTOUR_HW_RATIO_MAX;//流动条（待击打）长宽比最大值
    float FLOW_STRIP_CONTOUR_HW_RATIO_MIN;//流动条（待击打）长宽比最小值
    float FLOW_STRIP_CONTOUR_AREA_RATIO_MIN;//装甲板轮廓占旋转矩形面积比最小值
    float FLOW_STRIP_CONTOUR_INTERSETION_AREA_MIN;//流动条占旋转矩形面积比最小值

	float TWIN_ANGEL_MAX;//扇叶和装甲板匹配时极坐标角度差的最大值
	long INTERSETION_CONTOUR_AREA_MIN;//扇叶与装甲板匹配时的最小重合面积

	long TARGET_CHANGE_DISTANCE_MAX;//目标未更改时，目标装甲板中心与原目标装甲板中心的距离变化最大值
	long TWIN_POINT_MAX;//两个点相同时距离最大值
};


#endif //PARAM_STRUCT_DEFINE_H

