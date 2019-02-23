#ifndef PROGRESS_INDICATOR_HPP_PPI6TCYK
#define PROGRESS_INDICATOR_HPP_PPI6TCYK

#include <iostream>

class ProgressIndicator
{
public:
	ProgressIndicator(){
		width_ = getProgressMaxWidth();
		style_finished_ = '=';
		style_unfinished_= ' ';
	}
	
	void ProgressTo(size_t percent){
		if (percent > 100) return;

		auto &outs = std::cout;
		outs << "[";
		for (size_t idx = 0; idx < width_; ++idx) {
			if (100*idx/(double)width_ < percent) {
				outs << style_finished_;
			}else{
				outs << style_unfinished_;
			}
		}
		outs
			<< "]"
			<< percent << "%"
			<< "\r" << std::flush;
	}

private:
	size_t getProgressMaxWidth(){
		// TODO, need a way to get console width in char
		return 80;
	}

private:
	size_t width_;
	char style_finished_;
	char style_unfinished_;

};

#endif /* end of include guard: PROGRESS_INDICATOR_HPP_PPI6TCYK */
