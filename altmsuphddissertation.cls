% MSU Ph.D Dissertation class file
% Copyright by Clifford E. Weil and MSU Board of Trustees 2015
% This file must not to alter or distributed.

% I'm ignoring this, so use at your own risk - DMA

% New users should download the latest distribution from
% http://www.math.msu.edu/~weil/MSU_Ph.D._Dissertation.zip

% Report bugs to Clifford Weil (weil@math.msu.edu).
% Latest revision February, 2015 
% Includes modifications by Daniel Alt

% Identification
\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{altmsuphddissertation}

% Bring in the regular book class
\LoadClass[12pt,oneside]{book}

% Bring in needed packages
\RequirePackage{ifthen}
\RequirePackage{setspace}
\RequirePackage[titles,subfigure]{tocloft}
\RequirePackage{subfig}
\RequirePackage[margin=1in]{geometry}
\RequirePackage{pdflscape}
\RequirePackage{fancyhdr}
\RequirePackage{rotating}
\RequirePackage[bookmarksdepth=3]{hyperref} %Keeps sublevel PDF bookmarks which would otherwise be supressed by
								                            %the action of getting rid of appendix subheadings.

\@ifpackageloaded{hyperref}
%If hyperref is loaded, define tocentry to use alternate form for PDF index. In plain English, this gets rid of 
%unwanted formatting commands for the bookmarks in the PDF.
{\newcommand{\tocentry}[2]{\addcontentsline{toc}{chapter}{\texorpdfstring{#1}{#2}}}}

%%If hyperref is NOT loaded, define tocentry to just add the contents line
%%Also define the phantomsection command (included in hyperref) to do nothing
%{\newcommand{\tocentry}[2]{\addcontentsline{toc}{chapter}{#1}}
%\renewcommand{\phantomsection}{\relax}
%}

\newcommand{\chapname}{Chapter}
\newcommand\covername{Appendix}
\renewcommand{\appendixname}{Appendix}

% Change to double spacing as defined by MS Word
% Redefine the \doublspacing command
\renewcommand{\doublespacing}{%
	\setstretch {1.9}%  default
	\ifcase \@ptsize \relax % 10pt
	\setstretch {1.9}%
	\or % 11pt
	\setstretch {1.9}%
	\or % 12pt
	\setstretch {1.9}%
	\fi
}

% Number all levels of document divisions
\setcounter{secnumdepth}{6}

% Set depth of table of contents
\setcounter{tocdepth}{6}

% Set second level of sub(super) scripts to 10 pt.
% Thanks to Lee Larson for this fix.
\DeclareMathSizes{12}{12}{10}{10}
\DeclareMathSizes{10}{10}{10}{10}
% Set footnote font size to 12pt.

% Define the command \unit 
\newcommand*{\unit}[1]{\def\fromunit{#1}}

%Define the Title Page
\newcommand\maketitlepage{\begin{titlepage}%
    \vspace*{.55in}
    \begin{center}%
    \MakeUppercase{\@title}% DO NOT REMOVE THE FOLLOWING LINE
           
	\begin{doublespace}% DO NOT REMOVE THE FOLLOWING BLANK LINE
           
           By
	      
        \begin{tabular}[t]{c}%
        \@author
        \end{tabular}%
        \end{doublespace}
       %\vspace{\fill} - Cliff insists this is right.  He is incorrect - everyone who has left this in has been told to change it.
			\vspace{2.5in} %Use this one.  Seriously. (This is the distance between your name and ``A DISSERTATION'') - DMA
        {%
        A  DISSERTATION 
  	\vspace{\baselineskip}%

	Submitted to \\
	Michigan State University \\
	in partial fulfillment of the requirements \\
	for the degree of 
   
	\vspace{\baselineskip}%
	\fromunit % Inserts unit name and degree type%
  
	\vspace{\baselineskip}%
	{\number\year}  
	} 
	\vspace{\baselineskip}
	\end{center}
\end{titlepage}}%
 
% Define the command \abstractname
 \newcommand{\abstractname}{\textbf{ABSTRACT}}
 
%Define the abstract environment for the dissertation
  \newenvironment{abstract}{%
	\thispagestyle{empty}
         \pagenumbering{roman}
         \begin{center}%
         \bfseries \abstractname\vspace{\baselineskip}
         
          \MakeUppercase{\@title}
        
          \vspace{\baselineskip}
       
          By 
	 \vspace{\baselineskip}
	      
	 \begin{tabular}[t]{c}%
          \@author
          \end{tabular}
          \end{center}
     
         \begin{doublespace}
         \addtocounter{page}{1}
         } 
         {\end{doublespace}\pagestyle{empty}\newpage}

% Define the command \pubabstractname
 \newcommand{\pubabstractname}{\textbf{PUBLIC ABSTRACT}}
 
%Define the pubabstract environment for the dissertation
\newcounter{pubabs}
\newenvironment{pubabstract}{%
	\setcounter{pubabs}{\value{page}}
	\thispagestyle{empty}
         %\pagestyle{empty}
	\pagenumbering{roman}
         \begin{center}%
         \bfseries \pubabstractname\vspace{\baselineskip}%\value{page}
         
         \MakeUppercase{\@title}% DO NOT REMOVE THE FOLLOWING BLANK LINE
        
         \vspace{\baselineskip}% DO NOT REMOVE THE FOLLOWING BLANK LINE
       
         By 
	\vspace{\baselineskip}
	      
	\begin{tabular}[t]{c}%
         \@author
         \end{tabular}
         \end{center}
     
	\begin{doublespace}
	} 
{\end{doublespace}\newpage\setcounter{page}{\value{pubabs}}
	}
   
% Define the Copyright Page
      \newenvironment{copyrt}{%
      \newpage
      \thispagestyle{empty}
      \vspace*{\fill}
      \begin{center}
      \begin{tabular}{l}
      Copyright by\\
      \MakeUppercase{\@author}\\
      \number\year
      \end{tabular}
      \end{center}\vfill}
     {\newpage}
     
% Define the Dedication Page
\newcommand{\dedname}{DEDICATION}
\newenvironment{dedication}{%
	\newpage
	\thispagestyle{plain}
	\pagestyle{plain}
	\vspace*{\fill}}
	{
\vfill}
             
% Define the Acknowledgement Page
\newcommand{\ackname}{ACKNOWLEDGMENTS}
\newenvironment{acknowledgment}{%
	\newpage
	\thispagestyle{plain}
	\pagestyle{plain}
	\begin{center}
	{\bfseries\ackname}
	\vspace{\baselineskip}
	\end{center}
	\begin{doublespace}
	}
	{\end{doublespace}\thispagestyle{plain}
\pagestyle{plain}}
     
% Define the Preface Page
\newcommand{\prefname}{PREFACE}
\newenvironment{preface}{%
     	\newpage
      	\thispagestyle{plain}
      	\pagestyle{plain}
       	\begin{center}
     	{\bfseries\prefname}
    	\vspace{\baselineskip}
     	\end{center}
	\begin{doublespace}
	}
     	{\thispagestyle{plain}
	\end{doublespace}
\pagestyle{plain}}

% Redefine the \@chapter command to put "Chapter" 
% before each chapter entry in the ToC and to put
% "Appendix" before each appendix entry in the ToC.
% Replaced \chaptername by \@chapapp 7-26-12

\def\@chapter[#1]#2{
		\ifnum \c@secnumdepth >\m@ne %If section depth is greater than -1??
				\if@mainmatter %If we are in the main matter...
						\refstepcounter{chapter}%
						\vspace*{-4\baselineskip} %Affects display of chapter title in actual chapter
						\typeout{\@chapapp\space\thechapter.}%
						\ifx\chaptername\chapname %If this is a main chapter...
									\tocentry{\protect\numberline{\@chapapp\space\thechapter}#1} 
													{\@chapapp\space\thechapter\space-\space#1} %Set the TOC entry for top level
													%Here and elsewhere, Cliff uses a different approach, but that approach doesn't actually seem to WORK for me.
													%The text in the first brackets is the formatted text in the document, and in the second, the unformatted text
													%for the PDF bookmarks.
						\else	
									\ifx\covername\appendixname %Appendix cover page?		
									\else %If this is an appendix chapter...	
  									  	\addtocontents{toc}{\protect\setlength{\cftbeforechapskip}{0pt}} %Single space appendix titles in TOC
												\tocentry{\protect\numberline{\@chapapp\space\thechapter}#1}
														{\@chapapp\space\thechapter\space-\space#1}	%Set the TOC entry for top level
									\fi							 				
						\fi%
				\else %If this is NOT mainmatter..
						\addcontentsline{toc}{chapter}{#1}%
        \fi
		\else %Not sure when this triggers, honestly - DMA.
				%\tocentry{#1}{#1}
        \addcontentsline{toc}{chapter}{#1}%
    \fi

		%Do in all cases?
    \chaptermark{#1}%
    \if@twocolumn %If this is a two column layout
           \@topnewpage[\@makechapterhead{#2}]%
    \else
           \@makechapterhead{#2}% Chapter headings in the chapters/Apps
           	\@afterheading
    \fi}
                    
% Rededefine the table of contents command 
\renewcommand\contentsname{TABLE OF CONTENTS}
\renewcommand\tableofcontents{
		\begin{singlespace}%
		\if@twocolumn
				\@restonecoltrue\onecolumn
    \else
				\@restonecolfalse
    \fi
		\chapter*{\vspace{-2.5\baselineskip}\centerline{\large \MakeUppercase\contentsname} %Put the phrase ``TABLE OF CONTENTS''
		\@mkboth{\MakeUppercase\contentsname}{\MakeUppercase\contentsname}}%
		\vspace{-\baselineskip}
		\@starttoc{toc} %Start building the actual contents of the TOC
    \if@restonecol\twocolumn\fi
		\end{singlespace}
		}
  
\newcommand{\TOC}{
	\clearpage
	\pagestyle{plain}
	\pdfbookmark[0]{Table of Contents}{tocline} %Add a bookmark in the PDF to the TOC
	\tableofcontents
	\clearpage
	\pagestyle{plain}
	}

	\renewcommand{\cftchapleader}{\cftdotfill{\cftsecdotsep}}
	\renewcommand{\cftaftertoctitle}{\vspace{\baselineskip}}
  \setlength{\cftbeforechapskip}{\baselineskip}
	\renewcommand{\cftchapnumwidth}{6.5em}  
	   
%  Define the \LOT command to augment the \listofftables command
\renewcommand\listoftables{%
		\if@twocolumn
	\@restonecoltrue\onecolumn
		\else
	\@restonecolfalse
		\fi
	\chapter*{\vspace{-2.5\baselineskip}\centerline{\large \MakeUppercase
	\listtablename}}
	\tocentry{\textbf{LIST OF TABLES}}{List of Tables}
	
	\@mkboth{\MakeUppercase\listtablesname}%
	{\MakeUppercase\listtablename}%
	\begin{singlespace} 
	\vspace*{-\baselineskip}
	\@starttoc{lot}%
		\if@restonecol\twocolumn
		\fi
	\end{singlespace}
	}
	
\newcommand{\LOT}{
	\clearpage
	\setlength\cftbeforetabskip{\baselineskip}
	\listoftables
	\clearpage
	\pagestyle{plain}}
    
	\renewcommand{\cftafterlottitle}{\vspace{\baselineskip}}
	\renewcommand{\cfttabnumwidth}{6em}  
	\renewcommand{\cfttabpresnum}{Table }  
	\renewcommand{\cfttabaftersnum}{:}   
        
% Define the \LOF command to augment the \listoffigures command
	\renewcommand\listoffigures{%
		\if@twocolumn
	\@restonecoltrue\onecolumn
		\else
	\@restonecolfalse
		\fi
	\chapter*{\vspace{-2.5\baselineskip}\centerline{\large \MakeUppercase\listfigurename}}
	\tocentry{\textbf{LIST OF FIGURES}}{List of Figures}
	 \@mkboth{\MakeUppercase\listfigurename}%
	{\MakeUppercase\listfigurename}%
	\vspace*{-1\baselineskip} 
	\@starttoc{lof}%
		\if@restonecol\twocolumn
		\fi
}

\newcommand{\LOF}{
	\clearpage
	\setlength\cftbeforefigskip{\baselineskip}
	\listoffigures
	\clearpage
	\pagestyle{plain}}

	\renewcommand{\cftafterloftitle}{\vspace{\baselineskip}}
	\renewcommand{\cftfignumwidth}{6em}  
	\renewcommand{\cftfigpresnum}{Figure }
	\renewcommand{\cftfigaftersnum}{:}      
	        
% Define the KEY TO SYMBOLS
\newenvironment{symbols}{%
	\clearpage
	\thispagestyle{plain}\pagestyle{plain}
	\phantomsection
	\begin{center}
	\bfseries{\MakeUppercase{\large KEY TO SYMBOLS}}
	\end{center}
	\tocentry{KEY TO SYMBOLS}{Key To Symbols}%
	\vspace*{\baselineskip}}
{\newpage}

% Define the KEY TO ABBREVIATIONS
\newenvironment{abbrev}{%
	\clearpage
	\thispagestyle{plain}\pagestyle{plain}
	\phantomsection
	\begin{center}
	\bfseries{\MakeUppercase{\large KEY TO ABBREVIATIONS}}
	\end{center}
	\tocentry{KEY TO ABBREVIATIONS}{Key To Abbreviations}%
	\vspace*{\baselineskip}}
{\newpage}

% Single space quotation environments.
\renewenvironment{quotation}
	{\begin{singlespace}\list{}{\listparindent 1.5em%
	\itemindent    \listparindent
	\rightmargin   \leftmargin
	\parsep  \z@ \@plus\p@}%
	\item\relax}
{\endlist\end{singlespace}}
\renewenvironment{quote}
	{\begin{singlespace}\list{}{\rightmargin\leftmargin}%
	\item\relax}
{\endlist\end{singlespace}}    
               
% Redefine the \appendix command 
% to be used for a single appendix.
\renewcommand\appendix{\par
	\addtocontents{toc}{\protect\setcounter{tocdepth}{0}} %Supress TOC section headings for the appendix
	\clearpage\thispagestyle{plain}
	\phantomsection
	\vspace*{\fill}
	\begin{center}
	\large{\textbf{APPENDIX}}
	\vspace{\baselineskip}%
	\end{center}
	\tocentry{APPENDIX}{APPENDIX}
	\vfill
	\newpage
	\setcounter{chapter}{0}%
 	\setcounter{section}{0}%
	\renewcommand{\chaptername}{\appendixname} 
 	\gdef\chaptername{\appendixname}% 
 	\gdef\thechapter{\c@chapter\alpha} %
			%\gdef\thechapter{\@Alph\c@chapter}
	\clearpage
}

% Define the command \appendices to be used 
% for 2 or more appendices.
\newcommand\appendices{\par
	\addtocontents{toc}{\protect\setcounter{tocdepth}{0}} %Supress TOC section headings for the appendices
	\renewcommand{\covername}{Appendices}
	\clearpage\thispagestyle{plain}
	\phantomsection
	\vspace*{\fill}
	\begin{center}
	\large{\textbf{APPENDIX}}
	\vspace{\baselineskip}% 
	\end{center}
	\tocentry{APPENDICES}{Appendices}
	%\vfill
	\vspace*{\fill}
	\newpage
	\setcounter{chapter}{0}%
 	\setcounter{section}{0}%
 	\gdef\chaptername{\appendixname}%
 	\gdef\thechapter{\@Alph\c@chapter}
 	\renewcommand*{\theHchapter}{\Alph{chapter}}
  	\clearpage
}
     
% Single space the bibliography.
\newcommand{\bibnamecaps}{\typeout\MakeUppercase{\bibname}}
\renewenvironment{thebibliography}[1]
	{\clearpage\thispagestyle{plain}
	\phantomsection
	\vspace*{\fill}
	\begin{center}
	\large \textbf{\MakeUppercase{\bibname}}
	\vspace{\baselineskip}% 
	\end{center}
	\vfill
	\addtocontents{toc}{\protect\setlength{\cftbeforechapskip}{\baselineskip}} %Double space before bibliography title in TOC
	\tocentry{\MakeUppercase{\bibname}}{\bibname}%Must be BEFORE \newpage to make TOC number correct
	\newpage
	\chapter*{\vspace{-2.2\baselineskip}\centerline{ \large{\MakeUppercase{\bibname}}}}%
	\@mkboth{\MakeUppercase\bibname}{\MakeUppercase\bibname}%
       	\begin{singlespace}
	\list{\@biblabel{\@arabic\c@enumiv}}%
	{\settowidth\labelwidth{\@biblabel{#1}}%
	\leftmargin\labelwidth
	\advance\leftmargin\labelsep
	\@openbib@code
	\usecounter{enumiv}%
	\let\p@enumiv\@empty
	\renewcommand\theenumiv{\@arabic\c@enumiv}}%
	\setlength{\itemsep}{.2in}
	\sloppy
      	\clubpenalty4000
      	\@clubpenalty \clubpenalty
      	\widowpenalty4000%
      	\sfcode`\.\@m}
      	{\def\@noitemerr
       	{\@latex@warning{Empty `thebibliography' environment}}%
	\endlist
	\end{singlespace}}
     
% Properly locates page number for landscape
\let\LS@makecol=\@makecol
\let\LS@makefcolumn=\@makefcolumn
\def\LS@rot{%
	\setbox\@outputbox\vbox{\hbox{\rotatebox{90}%
	{\makebox[-4.5in][l]{\raisebox{-.4in}{\the\value{page}}}\box\@outputbox}}}}


% Set the starting page style
\pagestyle{empty} 
 
