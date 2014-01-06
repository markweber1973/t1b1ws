##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=t1b1dataprocessortests
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/mark/t1b1workspace"
ProjectPath            := "/home/mark/t1b1workspace/t1b1dataprocessortests"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Mark
Date                   :=12/01/2013
CodeLitePath           :="/home/mark/.codelite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
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
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -g  -std=c++0x $(Preprocessors)
LinkOptions            :=  -lgtest -lpthread
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)." "$(IncludeSwitch)../t1b1dataprocessor" 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/maintests$(ObjectSuffix) $(IntermediateDirectory)/primitivescoretest$(ObjectSuffix) $(IntermediateDirectory)/boulderscoretest$(ObjectSuffix) $(IntermediateDirectory)/primitivetotalscoretest$(ObjectSuffix) $(IntermediateDirectory)/totalscoretest$(ObjectSuffix) $(IntermediateDirectory)/scorecardtest$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/maintests$(ObjectSuffix): maintests.cpp $(IntermediateDirectory)/maintests$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessortests/maintests.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/maintests$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/maintests$(DependSuffix): maintests.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/maintests$(ObjectSuffix) -MF$(IntermediateDirectory)/maintests$(DependSuffix) -MM "/home/mark/t1b1workspace/t1b1dataprocessortests/maintests.cpp"

$(IntermediateDirectory)/maintests$(PreprocessSuffix): maintests.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/maintests$(PreprocessSuffix) "/home/mark/t1b1workspace/t1b1dataprocessortests/maintests.cpp"

$(IntermediateDirectory)/primitivescoretest$(ObjectSuffix): primitivescoretest.cpp $(IntermediateDirectory)/primitivescoretest$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessortests/primitivescoretest.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/primitivescoretest$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/primitivescoretest$(DependSuffix): primitivescoretest.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/primitivescoretest$(ObjectSuffix) -MF$(IntermediateDirectory)/primitivescoretest$(DependSuffix) -MM "/home/mark/t1b1workspace/t1b1dataprocessortests/primitivescoretest.cpp"

$(IntermediateDirectory)/primitivescoretest$(PreprocessSuffix): primitivescoretest.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/primitivescoretest$(PreprocessSuffix) "/home/mark/t1b1workspace/t1b1dataprocessortests/primitivescoretest.cpp"

$(IntermediateDirectory)/boulderscoretest$(ObjectSuffix): boulderscoretest.cpp $(IntermediateDirectory)/boulderscoretest$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessortests/boulderscoretest.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/boulderscoretest$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/boulderscoretest$(DependSuffix): boulderscoretest.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/boulderscoretest$(ObjectSuffix) -MF$(IntermediateDirectory)/boulderscoretest$(DependSuffix) -MM "/home/mark/t1b1workspace/t1b1dataprocessortests/boulderscoretest.cpp"

$(IntermediateDirectory)/boulderscoretest$(PreprocessSuffix): boulderscoretest.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/boulderscoretest$(PreprocessSuffix) "/home/mark/t1b1workspace/t1b1dataprocessortests/boulderscoretest.cpp"

$(IntermediateDirectory)/primitivetotalscoretest$(ObjectSuffix): primitivetotalscoretest.cpp $(IntermediateDirectory)/primitivetotalscoretest$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessortests/primitivetotalscoretest.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/primitivetotalscoretest$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/primitivetotalscoretest$(DependSuffix): primitivetotalscoretest.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/primitivetotalscoretest$(ObjectSuffix) -MF$(IntermediateDirectory)/primitivetotalscoretest$(DependSuffix) -MM "/home/mark/t1b1workspace/t1b1dataprocessortests/primitivetotalscoretest.cpp"

$(IntermediateDirectory)/primitivetotalscoretest$(PreprocessSuffix): primitivetotalscoretest.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/primitivetotalscoretest$(PreprocessSuffix) "/home/mark/t1b1workspace/t1b1dataprocessortests/primitivetotalscoretest.cpp"

$(IntermediateDirectory)/totalscoretest$(ObjectSuffix): totalscoretest.cpp $(IntermediateDirectory)/totalscoretest$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessortests/totalscoretest.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/totalscoretest$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/totalscoretest$(DependSuffix): totalscoretest.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/totalscoretest$(ObjectSuffix) -MF$(IntermediateDirectory)/totalscoretest$(DependSuffix) -MM "/home/mark/t1b1workspace/t1b1dataprocessortests/totalscoretest.cpp"

$(IntermediateDirectory)/totalscoretest$(PreprocessSuffix): totalscoretest.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/totalscoretest$(PreprocessSuffix) "/home/mark/t1b1workspace/t1b1dataprocessortests/totalscoretest.cpp"

$(IntermediateDirectory)/scorecardtest$(ObjectSuffix): scorecardtest.cpp $(IntermediateDirectory)/scorecardtest$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/mark/t1b1workspace/t1b1dataprocessortests/scorecardtest.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/scorecardtest$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scorecardtest$(DependSuffix): scorecardtest.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/scorecardtest$(ObjectSuffix) -MF$(IntermediateDirectory)/scorecardtest$(DependSuffix) -MM "/home/mark/t1b1workspace/t1b1dataprocessortests/scorecardtest.cpp"

$(IntermediateDirectory)/scorecardtest$(PreprocessSuffix): scorecardtest.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scorecardtest$(PreprocessSuffix) "/home/mark/t1b1workspace/t1b1dataprocessortests/scorecardtest.cpp"


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
	$(RM) $(OutputFile)


