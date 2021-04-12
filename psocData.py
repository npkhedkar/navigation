import numpy as np
import matplotlib.pyplot as plt

# Extract data from serial connection output file. Toggled between flat, up, and down test run text files
fs = open(r"c:\Users\nkhedkar\Documents\PSoc Creator\ELE302 Workspace\navigation\psocOutputNavTrack1.txt", 'r')
savedLines = fs.readlines()
fs.close()

# setSpeed = 4.00 # define target speed
firstPixelTime = 445

# Scale samples to reflect time interval driven. 
# finalStats = savedLines[-2]
# timeString = "Total Time: "
# lenString = " Length: "
# lastPart = finalStats.split(",")
# totalTime = float(lastPart[0][len(timeString):])
# totalLength = float(lastPart[1][len(lenString):])

# initNumSamps = len(savedLines)
# timePerSamps = totalTime / initNumSamps
savedLines = savedLines[1:] # eliminate first and last couple lines

# Prepare to clean data
string0 = "Black Pixel L: "
string1 = " Black Pixel R: "
string2 = " Pixel Error: "
string3 = " Duty Cycle: "

string0Len = len(string0)
string3Len = len(string3)

# Collect raw data from each sample
blackPixelLs = []
blackPixelRs = []
pixelErrors = []
dutyCycles = []

cleanedLines = []

for line in savedLines:
    attr = line.split(",")
    goodStart = (attr[0][:len(string0)] == string0)
    goodEnd = (attr[-1][:len(string3)] == string3)
    if (goodStart and goodEnd):
        blackPixelL = int(attr[0][len(string0):])
        blackPixelLs.append(blackPixelL)

        blackPixelR = int(attr[1][len(string1):])
        blackPixelRs.append(blackPixelR)

        pixelError = int(attr[2][len(string2):])
        pixelErrors.append(pixelError)

        dutyCycle = float(attr[3][len(string3):])
        dutyCycles.append(int (dutyCycle))

        cleanedLines.append(line)

# Calculate more error metrics
# counter = 0
# sumError = 0
# sumPercentError = 0
# percentErrors = []
# avgErrors = []
# avgPercentErrors = []
# for error in errors:
#     counter += 1
#     sumError += error
#     avgError = sumError / counter
#     avgErrors.append(avgError)

#     percentError = 100 * error / setSpeed
#     sumPercentError += percentError
#     avgPercentError = sumPercentError / counter

#     percentErrors.append(percentError)
#     avgPercentErrors.append(avgPercentError)

# finalNumSamps = len(cleanedLines)
# timeStamps = timePerSamps * np.arange(finalNumSamps)

# def fourierTransform(timeData, timeInt):
#     fourierTransform = np.fft.fft(timeData)/len(timeData)
#     if (len(timeData)%2 == 0):
#         fourierTransform = fourierTransform[range(int(len(timeData)/2))]
#     else:
#         fourierTransform = fourierTransform[range(int(len(timeData)/2)+1)]
#     values = np.arange(len(timeData)/2)
#     sampFrequency = 1/timeInt
#     timePeriod = len(timeData)/sampFrequency
#     frequencies = values/timePeriod
#     return frequencies, fourierTransform

# timePassed = np.cumsum(tickTimes)
# distPerTick = 0.12435 # in ft
# dists = [distPerTick * (tickNum) for tickNum in tickNums]

# freqs, percentErrorFT = fourierTransform(percentErrors, timePerSamps)

samps = np.arange(len(cleanedLines))
sampTime = 30 # seconds
timePassed = samps / len(samps) * sampTime
firstPixelLine = np.ones(len(samps)) * firstPixelTime

normDutyCycles = np.array(dutyCycles) / 200 * 100  


# Plot error as function of time
fig, ax = plt.subplots(1, 3)
ax[0].plot(timePassed, blackPixelLs, color='blue', label="Left Edge")
ax[0].plot(timePassed, blackPixelRs, color='red', label="Right Edge")
ax[0].plot(timePassed, firstPixelLine, color='black', label="True Left Edge")
ax[0].set_xlabel("Time Elapsed [s]")
ax[0].set_ylabel("Timer Captures")
ax[0].set_title("Timer Captures for Edge Detect as Function of Time")


ax[1].plot(timePassed, pixelErrors, color='brown', label="Left Edge Error")
ax[1].set_xlabel("Time Elapsed [s]")
ax[1].set_ylabel("Error")
ax[1].set_title("Error in Edge Detect as Function of Time")

ax[2].plot(timePassed, normDutyCycles, color='green', label="Duty Cycle")
ax[2].set_xlabel("Time ELapsed [s]")
ax[2].set_ylabel("Duty Cycle (%)")
ax[2].set_title("Duty Cycle")

fig.legend()
plt.show()



# Plot distance traveled as function of time
# plt.plot(timePassed, dists, color='orange', label="Distance")
# plt.xlabel("Time Elapsed [s]")
# plt.ylabel("Distance Traveled [ft]")
# plt.title("Distance Traveled as Function of Time Passed")
# plt.legend()
# plt.show()

# # Plot fourier transform of percent error (exclude 0 frequency component)
# plt.plot(freqs[1:], np.abs(percentErrorFT[1:]), color='brown')
# plt.title("Fourier Transform of Percent Error")
# plt.xlabel("Frequency Spectrum [Hz]")
# plt.ylabel("Strength")
# plt.legend()
# plt.show()

# # Now narrow in on tested region statistics
# targetDist = 40 # 40 ft is total tested distance of car for flat, 36 ft for up/down
# targetTick = int(targetDist / distPerTick) + 1 # convert this into ticks
# startDist = 1.8 # we always started car 1.8 ft behind line for flat, 2.0 ft behind line for up/down
# startTick = int(startDist / distPerTick)
# endTick = startTick + targetTick
# startIndex = np.where(np.array(tickNums) == startTick)[0][0]
# endIndex = np.where(np.array(tickNums) == endTick)[0][0]

# # Get truncated raw data
# timePassedCut = timePassed[startTick:endTick]
# timePassedCut = [time - timePassedCut[0] for time in timePassedCut] # adjust so that time array starts at t=0
# distsCut = dists[startTick:endTick]
# distsCut = [dist - distsCut[0] for dist in distsCut] # adjust like timePassedCut
# errorsCut = errors[startTick:endTick]

# # Recompute average error statistics
# counter1 = 0
# sumErrorCut = 0
# sumPercentErrorCut = 0
# percentErrorsCut = []
# avgErrorsCut = []
# avgPercentErrorsCut = []
# for error in errorsCut:
#     counter1 += 1
#     sumErrorCut += error
#     avgErrorCut = sumErrorCut / counter1
#     avgErrorsCut.append(avgErrorCut)

#     percentErrorCut = 100 * error / setSpeed
#     sumPercentErrorCut += percentErrorCut
#     avgPercentErrorCut = sumPercentErrorCut / counter1

#     percentErrorsCut.append(percentErrorCut)
#     avgPercentErrorsCut.append(avgPercentErrorCut)

# freqsCut, percentErrorFTCut = fourierTransform(percentErrorsCut, timePerSamps)

# # Now repeat plots for cut versions
# # Plot error as function of time
# fig, ax = plt.subplots(1, 2)
# ax[0].plot(timePassedCut, errorsCut, color='blue', label="Error")
# ax[0].plot(timePassedCut, avgErrorsCut, color='black', label="Avg Error")
# ax[0].set_xlabel("Time Elapsed [s]")
# ax[0].set_ylabel("Error [ft/s]")
# ax[0].set_title("Error in Speed as Function of Time Passed (Test Rgn)")

# ax[1].plot(timePassedCut, percentErrorsCut, color='red', label="Percent Error")
# ax[1].plot(timePassedCut, avgPercentErrorsCut, color='green', label="Avg Percent Error")
# ax[1].set_xlabel("Time Elapsed [s]")
# ax[1].set_ylabel("Percent Error")
# ax[1].set_title("Percent Error in Speed as Function of Time Passed (Test Rgn)")

# fig.legend()
# plt.show()

# # Plot distance traveled as function of time
# plt.plot(timePassedCut, distsCut, color='orange', label="Distance")
# plt.xlabel("Time Elapsed [s]")
# plt.ylabel("Distance Traveled [ft]")
# plt.title("Distance Traveled as Function of Time Passed (Test Rgn)")
# plt.legend()
# plt.show()

# # Plot fourier transform of percent error (exclude 0 frequency component)
# plt.plot(freqsCut[1:], np.abs(percentErrorFTCut[1:]), color='brown')
# plt.title("Fourier Transform of Percent Error (Test Rgn)")
# plt.xlabel("Frequency Spectrum [Hz]")
# plt.ylabel("Strength")
# plt.legend()
# plt.show()

