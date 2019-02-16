#ifndef CGraficos.h
#define CGraficos.h



class CGraficos {
	public:
		CGraficos()		{}
		~CGraficos()	{}

		void PlotarCartesiano(std::vector<double> X, std::vector<double> Y);
		void PlotarLog(std::vector<double> X, std::vector<double> Y);
		void PlotarLog_Log(std::vector<double> X, std::vector<double> Y);

};

#endif
