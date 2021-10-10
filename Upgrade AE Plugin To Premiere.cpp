// in .h
#include "PrSDKAESupport.h"
#include "AEFX_SuiteHelper.h"
typedef struct {
	A_u_char	blue, green, red, alpha;
} PF_Pixel_BGRA_8u;

typedef struct {
	A_u_char	Pr, Pb, luma, alpha;
} PF_Pixel_VUYA_8u;

typedef struct {
	PF_FpShort	blue, green, red, alpha;
} PF_Pixel_BGRA_32f;

typedef struct {
	PF_FpShort	Pr, Pb, luma, alpha;
} PF_Pixel_VUYA_32f;


// in global setup
if (in_data->appl_id == 'PrMr') {
		AEFX_SuiteScoper<PF_PixelFormatSuite1> pixelFormatSuite = AEFX_SuiteScoper<PF_PixelFormatSuite1>(in_data, kPFPixelFormatSuite, kPFPixelFormatSuiteVersion1, out_data);

		// add supported pixel formats
		(*pixelFormatSuite->ClearSupportedPixelFormats)(in_data->effect_ref);

		(*pixelFormatSuite->AddSupportedPixelFormat) (in_data->effect_ref, PrPixelFormat_VUYA_4444_32f);
		(*pixelFormatSuite->AddSupportedPixelFormat) (in_data->effect_ref, PrPixelFormat_BGRA_4444_32f);
		(*pixelFormatSuite->AddSupportedPixelFormat) (in_data->effect_ref, PrPixelFormat_VUYA_4444_8u);
		(*pixelFormatSuite->AddSupportedPixelFormat) (in_data->effect_ref, PrPixelFormat_BGRA_4444_8u);

	}

	
// above entry point
extern "C" DllExport
PF_Err PluginDataEntryFunction(
	PF_PluginDataPtr inPtr,
	PF_PluginDataCB inPluginDataCallBackPtr,
	SPBasicSuite* inSPBasicSuitePtr,
	const char* inHostName,
	const char* inHostVersion)
{
	PF_Err result = PF_Err_INVALID_CALLBACK;

	result = PF_REGISTER_EFFECT(
		inPtr,
		inPluginDataCallBackPtr,
		"Film Scans", // Name
		"MM FilmScan", // Match Name
		"Media Monopoly", // Category
		AE_RESERVED_INFO); // Reserved Info

	return result;
}


// entry point
case PF_Cmd_RENDER:
err = Render(in_data,
			out_data,
			params,
			output);
break;


// in Render()
AEFX_SuiteScoper<PF_PixelFormatSuite1> pixelFormatSuite =
		AEFX_SuiteScoper<PF_PixelFormatSuite1>(in_data,
			kPFPixelFormatSuite,
			kPFPixelFormatSuiteVersion1,
			out_data);

	PrPixelFormat destinationPixelFormat = PrPixelFormat_BGRA_4444_8u;

	pixelFormatSuite->GetPixelFormat(output, &destinationPixelFormat);

	AEFX_SuiteScoper<PF_Iterate8Suite1> iterate8Suite =
		AEFX_SuiteScoper<PF_Iterate8Suite1>(in_data,
			kPFIterate8Suite,
			kPFIterate8SuiteVersion1,
			out_data);

	switch (destinationPixelFormat)
	{

	case PrPixelFormat_BGRA_4444_8u:

		break;
	case PrPixelFormat_VUYA_4444_8u:

		break;
	case PrPixelFormat_BGRA_4444_32f:
	
		break;
	case PrPixelFormat_VUYA_4444_32f:
		
			
		break;
	default:
		//	Return error, because we don't know how to handle the specified pixel type
		return PF_Err_UNRECOGNIZED_PARAM_TYPE;
	}
