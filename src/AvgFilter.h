//
// Digital implementation of an average filter
// with variable number of samples using program
// provided storage
//

#include <Arduino.h>

#ifndef _AVGFILTER_H
#define _AVGFILTER_H

class avgFilter {
	public:
		avgFilter(int aSamples, long *aStorage);
		void 	initialize();
		long	value(long aSample);
		
	private:
		long	*iReadings;
		int		iIndex;
		long 	iTotal;
		int		iCount;
		int		iSamples;
};


avgFilter::avgFilter(int aSamples, long *aStorage) {
	iSamples = aSamples; 
	iReadings = aStorage;
	initialize();
}

void avgFilter::initialize() {
	iIndex = 0;
	iTotal = 0;
	iCount = 0;
	for (int i=0; i<iSamples; i++) iReadings[i]=0;
}

long	avgFilter::value(long aSample) {
	iTotal -= iReadings[iIndex];
	iReadings[iIndex] = aSample;
	iTotal += aSample;
	if (++iIndex >= iSamples) iIndex = 0;
	if (++iCount > iSamples) iCount = iSamples;
	return (iTotal/iCount);
}

#endif  // _AVGFILTER_H

