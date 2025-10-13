#include <vector>
#include <memory>
#include <atomic>
#include <barrier>
#include "Utils/ConvolutionItems.h"
#include "GeometricalPartitioning/VariantType.h"

class MyThread {
public:
    MyThread(ConvolutionItems &items, int nStart, int nEnd, int mStart, int mEnd,
             std::barrier<> *barrier, std::vector<std::unique_ptr<std::atomic<bool>>> &flags,
             VariantType variantType, int threadIndex);

    void run();
    // Other methods...

private:
    ConvolutionItems &items;
    int nStart, nEnd, mStart, mEnd;
    std::barrier<> *barrier;
    std::vector<std::unique_ptr<std::atomic<bool>>> &flags; // Update flags type here
    VariantType variantType;
    int threadIndex;

    bool areNeighborFlagsSet();
    void handleVariant1B( std::vector<int> &topRow, const std::vector<int> &bottomRow);
    void handleVariant1F(std::vector<int> &topRow, const std::vector<int> &bottomRow);
    void handleVariant2B(std::vector<int> &topRow, const std::vector<int> &bottomRow);
    void handleVariant2F(const std::vector<int> &topRow, const std::vector<int> &bottomRow);
};
