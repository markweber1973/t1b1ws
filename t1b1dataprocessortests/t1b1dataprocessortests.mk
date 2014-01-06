##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=t1b1dataprocessortests
ConfigurationName      :=Debug
WorkspacePath          := "/home/mark/t1b1ws"
ProjectPath            := "/home/mark/t1b1ws/t1b1dataprocessortests"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Mark
Date                   :=01/06/14
CodeLitePath           :="/home/mark/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="t1b1dataprocessortests.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lgtest -lpthread
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../t1b1dataprocessor 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g  -std=c++0x $(Preprocessors)
CFLAGS   :=  -g  -std=c++0x $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/maintests$(ObjectSuffix) $(IntermediateDirectory)/primitivescoretest$(ObjectSuffix) $(IntermediateDirectory)/boulderscoretest$(ObjectSuffix) $(IntermediateDirectory)/primitivetotalscoretest$(ObjectSuffix) $(IntermediateDirectory)/totalscoretest$(ObjectSuffix) $(IntermediateDirectory)/scorecardtest$(ObjectSuffix) $(IntermediateDirectory)/roundtest$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/maintests$(ObjectSuffix): maintests.cpp $(IntermediateDirectory)/maintests$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1ws/t1b1dataprocessortests/maintests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/maintests$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/maintests$(DependSuffix): maintests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/maintests$(ObjectSuffix) -MF$(IntermediateDirectory)/maintests$(DependSuffix) -MM "maintests.cpp"

$(IntermediateDirectory)/maintests$(PreprocessSuffix): maintests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/maintests$(PreprocessSuffix) "maintests.cpp"

$(IntermediateDirectory)/primitivescoretest$(ObjectSuffix): primitivescoretest.cpp $(IntermediateDirectory)/primitivescoretest$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1ws/t1b1dataprocessortests/primitivescoretest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/primitivescoretest$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/primitivescoretest$(DependSuffix): primitivescoretest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/primitivescoretest$(ObjectSuffix) -MF$(IntermediateDirectory)/primitivescoretest$(DependSuffix) -MM "primitivescoretest.cpp"

$(IntermediateDirectory)/primitivescoretest$(PreprocessSuffix): primitivescoretest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/primitivescoretest$(PreprocessSuffix) "primitivescoretest.cpp"

$(IntermediateDirectory)/boulderscoretest$(ObjectSuffix): boulderscoretest.cpp $(IntermediateDirectory)/boulderscoretest$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1ws/t1b1dataprocessortests/boulderscoretest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/boulderscoretest$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/boulderscoretest$(DependSuffix): boulderscoretest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/boulderscoretest$(ObjectSuffix) -MF$(IntermediateDirectory)/boulderscoretest$(DependSuffix) -MM "boulderscoretest.cpp"

$(IntermediateDirectory)/boulderscoretest$(PreprocessSuffix): boulderscoretest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/boulderscoretest$(PreprocessSuffix) "boulderscoretest.cpp"

$(IntermediateDirectory)/primitivetotalscoretest$(ObjectSuffix): primitivetotalscoretest.cpp $(IntermediateDirectory)/primitivetotalscoretest$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1ws/t1b1dataprocessortests/primitivetotalscoretest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/primitivetotalscoretest$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/primitivetotalscoretest$(DependSuffix): primitivetotalscoretest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/primitivetotalscoretest$(ObjectSuffix) -MF$(IntermediateDirectory)/primitivetotalscoretest$(DependSuffix) -MM "primitivetotalscoretest.cpp"

$(IntermediateDirectory)/primitivetotalscoretest$(PreprocessSuffix): primitivetotalscoretest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/primitivetotalscoretest$(PreprocessSuffix) "primitivetotalscoretest.cpp"

$(IntermediateDirectory)/totalscoretest$(ObjectSuffix): totalscoretest.cpp $(IntermediateDirectory)/totalscoretest$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1ws/t1b1dataprocessortests/totalscoretest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/totalscoretest$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/totalscoretest$(DependSuffix): totalscoretest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/totalscoretest$(ObjectSuffix) -MF$(IntermediateDirectory)/totalscoretest$(DependSuffix) -MM "totalscoretest.cpp"

$(IntermediateDirectory)/totalscoretest$(PreprocessSuffix): totalscoretest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/totalscoretest$(PreprocessSuffix) "totalscoretest.cpp"

$(IntermediateDirectory)/scorecardtest$(ObjectSuffix): scorecardtest.cpp $(IntermediateDirectory)/scorecardtest$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1ws/t1b1dataprocessortests/scorecardtest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scorecardtest$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scorecardtest$(DependSuffix): scorecardtest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scorecardtest$(ObjectSuffix) -MF$(IntermediateDirectory)/scorecardtest$(DependSuffix) -MM "scorecardtest.cpp"

$(IntermediateDirectory)/scorecardtest$(PreprocessSuffix): scorecardtest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scorecardtest$(PreprocessSuffix) "scorecardtest.cpp"

$(IntermediateDirectory)/roundtest$(ObjectSuffix): roundtest.cpp $(IntermediateDirectory)/roundtest$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mark/t1b1ws/t1b1dataprocessortests/roundtest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/roundtest$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/roundtest$(DependSuffix): roundtest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/roundtest$(ObjectSuffix) -MF$(IntermediateDirectory)/roundtest$(DependSuffix) -MM "roundtest.cpp"

$(IntermediateDirectory)/roundtest$(PreprocessSuffix): roundtest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/roundtest$(PreprocessSuffix) "roundtest.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/maintests$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/maintests$(DependSuffix)
	$(RM) $(IntermediateDirectory)/maintests$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/primitivescoretest$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/primitivescoretest$(DependSuffix)
	$(RM) $(IntermediateDirectory)/primitivescoretest$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/boulderscoretest$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/boulderscoretest$(DependSuffix)
	$(RM) $(IntermediateDirectory)/boulderscoretest$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/primitivetotalscoretest$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/primitivetotalscoretest$(DependSuffix)
	$(RM) $(IntermediateDirectory)/primitivetotalscoretest$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/totalscoretest$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/totalscoretest$(DependSuffix)
	$(RM) $(IntermediateDirectory)/totalscoretest$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/scorecardtest$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/scorecardtest$(DependSuffix)
	$(RM) $(IntermediateDirectory)/scorecardtest$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/roundtest$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/roundtest$(DependSuffix)
	$(RM) $(IntermediateDirectory)/roundtest$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/t1b1dataprocessortests"


